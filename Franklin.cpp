#include "Franklin.h"
#include "lifestuff.h"
#include "powerpellet.h"
#include "bullet.h"
//#include "timer.h"
#include "enemy.h"
#include <QDebug>
#include <QTimer>


extern bool collide;
QTimer timer;

rect::rect(int boardData[12][12])
{
       QPixmap image("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\cat.png");
       image = image.scaledToWidth(60);
       image = image.scaledToHeight(60);
       setPixmap(image);

       //"A:\\Development\\C++ - CS 2\\CS2-Project\\CS2-Project\\images\\Tweety.png"





       row = 6;
       column = 7;
       setPos(50 + column * 50, 50 + row * 50);

       for (int i = 0; i < 12; i++)
           for (int j = 0; j < 12; j++)
              data[i][j] = boardData[i][j];

}

void rect::holdpistol()
{
    QPixmap image1 ("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\fire.png");
    image1=image1.scaledToHeight(60);
    image1=image1.scaledToWidth(60);
    setPixmap(image1);
    //setPos(50 + 10 * 50, 50 + 10 * 50);

}

void rect::gobacktonormal()
{
    QPixmap image("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\cat.png");
    image = image.scaledToWidth(60);
    image = image.scaledToHeight(60);
    setPixmap(image);
    timer.stop();

}




void rect::angrymeow()
{
    QPixmap image("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\catangry.png");
    image = image.scaledToWidth(60);
    image = image.scaledToHeight(60);
    setPixmap(image);
    //class timer t;
    //t.go();
    //scene()->addItem(&t);



    timer.stop();

}


void rect::keyPressEvent(QKeyEvent* event)
{

    if (event->key() == Qt::Key_Up && data[row - 1][column] >= 0)
       {
           row--;
       }
       else if (event->key() == Qt::Key_Down && data[row + 1][column] >= 0)
       {
           row++;
       }
       else if (event->key() == Qt::Key_Right && data[row][column + 1] >= 0)
       {
           column++;
       }
       else if (event->key() == Qt::Key_Left && data[row][column - 1] >= 0)
       {
           column--;
       }
       setPos(50 + column * 50, 50 + row * 50);


// controling collision with power pellets
       QList<QGraphicsItem *> colliding_items_pellet = collidingItems();
       for (int i =0, n=colliding_items_pellet.size(); i<n; i++){
           if (typeid(*(colliding_items_pellet[i]))==typeid(powerpellet)){
               scene()->removeItem(colliding_items_pellet[i]);
               //add code to make kitty indestructable for 10 secs

               angrymeow();
               angry = true;




               QTimer *powertime=new QTimer;
               connect (powertime, SIGNAL(timeout()), this, SLOT(gobacktonormal()));
               powertime->start(10000);
               angry = false;
               //add code to display a 10 sec timer



           }
       }


       // controlling collision with bullets
       QList<QGraphicsItem *> colliding_items_bullet = collidingItems();
       for (int i =0, n=colliding_items_bullet.size(); i<n; i++){
           if (typeid(*(colliding_items_bullet[i]))==typeid(bullet)){
               scene()->removeItem(colliding_items_bullet[i]);
               //change pic for one sec
               holdpistol();
               connect(&timer, SIGNAL(timeout()),this, SLOT (gobacktonormal()));
               timer.start(1000);
               //enemy->life--;
              // if (enemy->life==0)
                 //  scene()->removeItem(enemy);
               // add code to take half a life from enemy and check if enemy life is 0 to remove him



           }
       }

       QList<QGraphicsItem *> colliding_items_enemy = collidingItems();
       for (int i =0, n=colliding_items_enemy.size(); i<n; i++){
           if (typeid(*(colliding_items_enemy[i]))==typeid(Enemy)){

               if (angry == false)
               life--;
               //add function to remove one heart

               //changeHeart(0, 8);
               data[12][12];

               setPos(50 + column * 50, 50 + row * 50);


           }
       }


}