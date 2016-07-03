#include "widget.h"
#include <QPaintEvent>
#include <QPainter>

Widget::Widget(QWidget *parent) : QWidget(parent)
{

}

Widget::~Widget()
{

}

void Widget::setPixmap(const QPixmap &pixmap)
{
    this->pixmap = pixmap;
    update();
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    foreach (const QRect &r, e->region().rects()) {
        painter.drawPixmap(r, pixmap, r);
    }
}
