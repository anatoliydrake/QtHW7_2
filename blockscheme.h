#ifndef BLOCKSCHEME_H
#define BLOCKSCHEME_H

#include <QObject>
#include <QGraphicsItem>
#include <QContextMenuEvent>
#include <QBrush>
#include <QCursor>


class Blockscheme : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QBrush brush)
public:
    explicit Blockscheme(QObject *parent = nullptr, int g = 0);
    void setBrush(QBrush brush) {this->brush = brush; emit reDraw();}
signals:
    void reDraw();
    void dblClick();
public slots:
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
private:
    enum Geometry {RECTANGLE, ELLIPS, RECT};
    int x, y;
    Geometry geometry;
    QPoint bpoint;
    bool moving;
    QBrush brush;
    QPointF target;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
public:

};

#endif // BLOCKSCHEME_H
