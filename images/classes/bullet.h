#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>



class bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    bullet(QGraphicsItem* parent=0);
public slots:
    void move();
    double getMaxRange();
    double getDistanceTravelled();
    void setmaxRange(double rng);
    void setDistanceTravelled(double dist);
private:
    //deleting the bullet after its maximum range
    double maxRange;
    double distanceTravelled;

};

#endif // BULLET_H
