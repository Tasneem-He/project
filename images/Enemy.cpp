#include "Enemy.h"
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QTimer>
#include <QDebug>
Enemy::Enemy(int boardData[12][12]){

    // Set Image of the enemy
    QPixmap image("C:\\Users\\Tasnem\\Downloads\\pngegg.png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        setPixmap(image);
  // Set Position
        row = 10;
        column = 6;
        setPos(50 + column * 50, 50 + row * 50);
 // Set data Array
    for (int i = 0; i < 10; i++)
           for (int j = 0; j < 10; j++)
               data[i][j] = boardData[i][j];
    // calling the move function periodically so it moves every certain amount of time
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(1000);

}

void Enemy::move(){
    // move enemy


    if (data[row + 1][column ] >= 0 && pos().y() <  550){
           setPos(x(),y()+12);

}
    else if (data[row - 1][column] >= 0 && pos().y() > 100 ){
      setPos(x(),y()-12);
    }

    else if (data[row][column - 1] >= 0 && pos().x() > 100){
           setPos(x()-12,y());

}

    else if (data[row][column + 1] >= 0 && pos().x() <  550){

           setPos(x()+20,y());

    }







}

