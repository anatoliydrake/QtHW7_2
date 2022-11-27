#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "blockscheme.h"
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>


class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsScene *scene;
    int geo;

protected:
    void mouseReleaseEvent(QMouseEvent *event) override;
//    void mousePressEvent(QMouseEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
//    void paintEvent(QPaintEvent *event) override;
private slots:
    void reDraw();
    void wheelEvent(QWheelEvent* event) override;
public:
    static int shape;
};
#endif // MAINWINDOW_H
