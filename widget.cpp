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

void Widget::addRect(const QRect &r)
{
    if (r.isValid()) {
        QPainter painter(&pixmap);
        painter.setPen(QColor(0, 0, 255));
        painter.setBrush(QColor(255, 0, 0, 255/2));
        painter.drawRect(r);
        painter.end();
        update(r.adjusted(0,0,1,1));
    }
}
