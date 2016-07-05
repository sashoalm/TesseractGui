#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "thread.h"

#include <QFileDialog>
#include <QtConcurrentRun>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
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
    ui->widget->setPixmap(text);
    cancelFlag = false;
    QtConcurrent::run(runThread, text, ui->widget, &cancelFlag);
}

void MainWindow::on_pushButton_2_clicked()
{
    cancelFlag = true;
}
