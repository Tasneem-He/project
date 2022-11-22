#ifndef ENEMY_H
#define ENEMY_H

#include <QKeyEvent>
#include <QList>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(int boardData[12][12]);


private:
    int row, column;
    int data[10][10];
public slots:
    void move();
};

#endif // ENEMY_H
