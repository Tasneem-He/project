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
    Enemy(int boardData[12][12], int rows, int columns);
    int life=2;


private:
    int rows, columns;
    int data[12][12];
    int lives =2;
public slots:
    void move();
};

#endif // ENEMY_H
