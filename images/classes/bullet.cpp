#include "bullet.h"
#include "QtWidgets/qgraphicsscene.h"
#include <QPixmap>
#include <qmath.h>
#include <QList>
#include <stdlib.h> //rand()-> really large integer
#include <QDebug>

bullet::bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/images/annoyed-expression-cute-bullet-cartoon-character_152558-32769.jpg.webp"));
    //set random position
    int random_number= arc4random();
    setPos(random_number,0);
    //intialize values
    maxRange = 3;
    distanceTravelled =0;
}
void bullet::move(){
    int stepSize = 30;
    double theta =rotation(); //degrees

    double dy =stepSize *qSin(qDegreesToRadians(theta));
    double dx =stepSize *qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);

//if bullet collides with enemy, destroy both
QList<QGraphicsItem *> colliding_items = collidingItems();
for (int i =0, n=colliding_items.size(); i<n; i++){
    //if (typeid(*(colliding_items[i]))==typeid(enemy)){
        //remove them both
        scene()->removeItem(colliding_items[i]);
        scene()->removeItem(this);
        //delete them both
        delete colliding_items[i];
        delete this;
        return;
    }
}


