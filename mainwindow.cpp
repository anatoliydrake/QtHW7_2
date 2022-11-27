#include "mainwindow.h"
#include <QGridLayout>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    srand(clock());
    scene = new QGraphicsScene(this);
    setScene(scene);
}

MainWindow::~MainWindow()
{
}

int MainWindow::shape = 0;

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !itemAt(event->pos()))
    {
        Blockscheme* block = new Blockscheme(this, MainWindow::shape % 3);
        connect(block, SIGNAL(reDraw()), this, SLOT(reDraw()));
        block->setPos(event->pos().x(), event->pos().y());
        block->setFlags(QGraphicsItem::ItemIsMovable);
        scene->addItem(block);
        MainWindow::shape++;
    }
    if (event->button() == Qt::RightButton)
    {
        delete itemAt(event->pos());
    }
}

//void MainWindow::mousePressEvent(QMouseEvent *event)
//{
//    if(event->button() == Qt::MiddleButton)
//    {
//        QPainter* painter = (QPainter*)itemAt(event->pos());
//        painter->rotate(10.0);
//    }
//}

void MainWindow::reDraw()
{
    scene->update();
    update();
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
        const ViewportAnchor anchor = transformationAnchor();
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        int angle = event->angleDelta().y();
        qreal factor;
        if (angle > 0) {
            factor = 1.1;
        } else {
            factor = 0.9;
        }
        scale(factor, factor);
        setTransformationAnchor(anchor);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    const ViewportAnchor anchor = transformationAnchor();
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    qreal factor;
    if (event->key() == Qt::Key_Equal) {
        factor = 1.1;
    }
    if (event->key() == Qt::Key_Minus) {
        factor = 0.9;
    }
    scale(factor, factor);
    setTransformationAnchor(anchor);
}

//void MainWindow::paintEvent(QPaintEvent *event)
//{
//    QPainter painter(this);
//    painter.rotate(10.0);
//}



