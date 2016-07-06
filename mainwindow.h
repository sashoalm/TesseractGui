#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &text);

    void on_pushButton_2_clicked();

private:
    void waitForTesseractFinished();
    volatile bool cancelFlag;
    volatile bool tesseractIsRunning;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
