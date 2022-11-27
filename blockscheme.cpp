#include "blockscheme.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>


Blockscheme::Blockscheme(QObject *parent, int geom)
    : QObject{parent}
{
    x = 0;
    y = 0;
    brush.setColor(QColor(rand() % 256, rand() % 256, rand() % 256));
    brush.setStyle(Qt::BrushStyle::SolidPattern); // Полностью закрашивать
    switch(geom)
    {
    case 0:
        geometry = Geometry::ELLIPS;
        break;
    case 1:
        geometry = Geometry::RECT;
        break;
    case 2:
        geometry = Geometry::RECTANGLE;
        break;
    }
    setPos(0,0);
    moving = false;
}

void Blockscheme::paint(QPainter *painter, const QStyleOptionGraphicsItem
*option, QWidget *widget)
{
    painter->setBrush(brush);
//    painter->rotate(10.0);
    if (geometry == Geometry::ELLIPS) painter->drawEllipse(x, y, 200, 100);
    if (geometry == Geometry::RECTANGLE) painter->drawRect(x, y, 200, 100);
    if (geometry == Geometry::RECT) painter->drawRect(x, y, 100, 100);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
QRectF Blockscheme::boundingRect() const // Обязателен для переопределения
{
    return QRectF(x, y, 200, 100); // Текущие координаты
}
void Blockscheme::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
}
void Blockscheme::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
}
void Blockscheme::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton)
    {
        QPainter* painter = (QPainter*)this;
        painter->rotate(10.0);
    } else
    this->setPos(mapToScene(event->pos()));
}


