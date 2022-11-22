#include "enemy.h"
#include "Franklin.h"
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include "bullet.h"
#include "lose.h"
Enemy::Enemy(int boardData[12][12], int rows, int columns){

    // Set Image of the enemy
    QPixmap image("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\frame-1.png");
        image = image.scaledToWidth(30);
        image = image.scaledToHeight(30);
        setPixmap(image);
  // Set Position
        setPos(50 + columns * 50, 50 + rows * 50);
        this->l=l ;
 // Set data Array
    for (int i = 0; i < 12; i++)
           for (int j = 0; j < 12; j++)
               data[i][j] = boardData[i][j];
    // calling the move function periodically so it moves every certain amount of time
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(500);

}

void Enemy::move(){
    // move enemy


    if (data[rows + 1][columns ] >= 0 && pos().y() <  550){
           setPos(x(),y()+12);

}

    else if (data[rows][columns - 1] >= 0 && pos().x() > 100){
           setPos(x()-12,y());

}

    else if (data[rows][columns + 1] >= 0 && pos().x() <  550){

           setPos(x()+20,y());

}

    else if (data[rows - 1][columns] >= 0 && pos().y() > 100 ){
      setPos(x(),y()-12);
}





    QList<QGraphicsItem *> colliding_items_enemy = collidingItems();
    for (int i =0, n=colliding_items_enemy.size(); i<n; i++){
        if (typeid(*(colliding_items_enemy[i]))==typeid(rect)){
            rect * franklin = dynamic_cast<rect*>(colliding_items_enemy[i]);
                       if(franklin->angry)
                       {
                           continue;
                       }
                        else
                       {
                         franklin->life -- ;
                        }
                       if (franklin->life<= 0)
                       {
                           scene()->addItem(l[0]);
                           l[0]->setPos(50 + -2 * 50, 50 + -2 * 50);
                       }
if (data[rows - 1][columns] >= 0 && pos().y() > 100 )
            setPos(x(),y()-12);
 setPos(x()+20,y());

            data[12][12];






        }
    }


}


