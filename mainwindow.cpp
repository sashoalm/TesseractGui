#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "thread.h"

#include <QFileDialog>
#include <QTimer>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <QtConcurrent>
#else  // QT4
#include <QtConcurrentRun>
#endif  // QT5

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tesseractIsRunning = false;
}

MainWindow::~MainWindow()
{
    waitForTesseractFinished();
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    const QString &file = QFileDialog::getOpenFileName(this, "", "", tr("Images (*.jpg *.tif *.png *.tiff *.bmp *.jpeg);;All files (*.*)"));
    if (!file.isEmpty()) {
        ui->lineEdit->setText(file);
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &text)
{
    waitForTesseractFinished();
    ui->widget->setPixmap(text);
    cancelFlag = false;
    tesseractIsRunning = true;
    QtConcurrent::run(runThread, text, ui->widget, &cancelFlag, &tesseractIsRunning);
}

void MainWindow::on_pushButton_2_clicked()
{
    cancelFlag = true;
}

void MainWindow::waitForTesseractFinished()
{
    if (tesseractIsRunning) {
        cancelFlag = true;

        QEventLoop loop;
        QTimer timer;
        timer.setInterval(100);
        connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
        timer.start();
        while (tesseractIsRunning) {
            loop.exec(QEventLoop::ExcludeUserInputEvents);
        }
    }
}
