#ifndef FRANKLIN_H
#define FRANKLIN_H

#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "lifestuff.h"
#include "enemy.h"
#include "bullet.h"
#include "win.h"
#include "home.h"
#include "lifestuff.h"



class rect: public QObject, public QGraphicsPixmapItem

{
    Q_OBJECT
public:
    int row, column;
    int data[12][12];
    rect(int boardData[12][12]);
    int life=3;
    bool angry=false;
    void killenemy();
    Enemy **e;
       bullet **b;
       home **h;
       lifestuff **f ;
       win **w;
       lose **l;

public slots:
    void keyPressEvent(QKeyEvent* event);
    void holdpistol();
    void gobacktonormal();
    void angrymeow();

};


#endif // FRANKLIN_H
