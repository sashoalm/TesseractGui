#ifndef PROGRESSWIDGET_H
#define PROGRESSWIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void setPixmap(const QPixmap &pixmap);
    void paintEvent(QPaintEvent *e);

signals:

public slots:
    void addRect(const QRect &r);

private:
    QPixmap pixmap;
};

#endif // PROGRESSWIDGET_H
