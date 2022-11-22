#include <QApplication>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
//#include <QMediaPlayer>
#include "Franklin.h"
#include "lifestuff.h"
#include "powerpellet.h"
#include "bullet.h"
#include "timer.h"
#include "enemy.h"
#include "game.h"
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

bool collide=false;


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    //create a scene
    QGraphicsScene *scene=new QGraphicsScene;
    //creating a view to visualizse the scene
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(650,650);
    view->setWindowTitle("GTA");
    QBrush brush(Qt::white);
    view->setBackgroundBrush(brush);
    // reading from a file to establish the map
    QFile file("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\Board.txt");
    file.open(QIODevice::ReadOnly);
    //putting the file data into stream and intizlaizing the 2d arrady
    QTextStream stream(&file);
    int boardData[12][12];
    QString temp;
    for (int i = 0; i < 12; i++){
            for (int j = 0; j < 12; j++)
            {
                stream >> temp;
                boardData[i][j] = temp.toInt();
            }
    }






    QPixmap walk("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\lilbush.png");
    walk = walk.scaledToWidth(40);
    walk = walk.scaledToHeight(45);

    QPixmap obstacle1("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\grass.png");
    obstacle1 = obstacle1.scaledToWidth(50);
    obstacle1 = obstacle1.scaledToHeight(50);

    QPixmap road_h("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\straight-b.png");
    road_h=road_h.scaledToWidth(50);
    road_h=road_h.scaledToHeight(50);

    QPixmap border("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\Bricks.png");
    border=border.scaledToWidth(50);
    border=border.scaledToHeight(50);

    QPixmap road_right_up("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\rightup.png");
    road_right_up=road_right_up.scaledToWidth(75);
    road_right_up=road_right_up.scaledToHeight(75);

    QPixmap road_left_up ("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\leftup.png");
    road_left_up=road_left_up.scaledToWidth(75);
    road_left_up=road_left_up.scaledToHeight(75);

    QPixmap rightdown ("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\rightdown.png");
    rightdown=rightdown.scaledToWidth(52);
    rightdown=rightdown.scaledToHeight(49);

    QPixmap leftdown ("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\leftdown.png");
    leftdown=leftdown.scaledToWidth(53);
    leftdown=leftdown.scaledToHeight(50);

    QPixmap vertical("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\vertical.png");
    vertical=vertical.scaledToWidth(52);
    vertical=vertical.scaledToHeight(52);

    QPixmap vertical_noborder("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\vert-noside.png");
    vertical_noborder=vertical_noborder.scaledToWidth(51);
    vertical_noborder=vertical_noborder.scaledToHeight((double)50.2);

    QPixmap vertical_noborder_right("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\vert-noside -right.png");
    vertical_noborder_right=vertical_noborder_right.scaledToWidth(30);
    vertical_noborder_right=vertical_noborder_right.scaledToHeight(50);

    QPixmap north_noborder("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\noborder-north.png");
    north_noborder=north_noborder.scaledToWidth(50);
    north_noborder=north_noborder.scaledToHeight(50);

    QPixmap south_noborder("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\noborder-south.png");
    south_noborder=south_noborder.scaledToWidth(50);
    south_noborder=south_noborder.scaledToHeight(50);

    QPixmap square("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\square.png");
    square=square.scaledToWidth(50);
    square=square.scaledToHeight(50);

    QPixmap heart("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\heart.png");
    heart=heart.scaledToWidth(50);
    heart=heart.scaledToHeight(50);














    QGraphicsPixmapItem boardItems[12][12];

    for (int i = 0; i < 12; i++)
           for (int j = 0; j < 12; j++)
           {
               // Set Image
               if (boardData[i][j] == -2)
                   boardItems[i][j].setPixmap(border);
               else if (boardData[i][j] == -1)
                   boardItems[i][j].setPixmap(obstacle1);

               else if (boardData [i][j]>0 && boardData[i][j]<10)
                   boardItems[i][j].setPixmap(road_h);
               else if (boardData [i][j]>26 && boardData[i][j]<36)
                   boardItems[i][j].setPixmap(road_h);
               else if (boardData [i][j]>48 && boardData[i][j]<58)
                   boardItems[i][j].setPixmap(road_h);

               else
                   boardItems[i][j].setPixmap(walk);

               // Set Position
               //boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

               // Add to the Scene
               //scene->addItem(&boardItems[i][j]);
           }
    for (int i=2; i<10; i++){
        boardItems[i][1].setPixmap(vertical);
    }
    for (int i=2; i<10; i++){
        boardItems[i][4].setPixmap(vertical);
    }
    for (int i=2; i<10; i++){
        boardItems[i][7].setPixmap(vertical);
    }
    for (int i=2; i<10; i++){
        boardItems[i][10].setPixmap(vertical);
    }

    boardItems[1][10].setPixmap(road_right_up);
    boardItems[1][1].setPixmap(road_left_up);
    boardItems[10][10].setPixmap(rightdown);
    boardItems[10][1].setPixmap(leftdown);
    boardItems[6][1].setPixmap(vertical_noborder);
    boardItems[6][10].setPixmap(vertical_noborder_right);
    boardItems[1][4].setPixmap(north_noborder);
    boardItems[1][7].setPixmap(north_noborder);
    boardItems[10][7].setPixmap(south_noborder);
    boardItems[10][4].setPixmap(south_noborder);
    boardItems[6][4].setPixmap(square);
    boardItems[6][7].setPixmap(square);
    //boardItems[0][8].setPixmap(heart);
    //boardItems[0][9].setPixmap(heart);
    //boardItems[0][10].setPixmap(heart);


    for (int i = 0; i < 12; i++)
           for (int j = 0; j < 12; j++)
           {


               // Set Position
               boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

               // Add to the Scene
               scene->addItem(&boardItems[i][j]);
           }

    class::rect r(boardData);
    scene->addItem(&r);
    r.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    r.setFocus();

    lifestuff heart1(0,8), heart2(0,9), heart3(0,10);
    scene->addItem(&heart1);
    scene->addItem(&heart2);
    scene->addItem(&heart3);

    powerpellet one(4,1), two(8,10);
    scene->addItem(&one);
    scene->addItem(&two);

    class::bullet bullet1(1,1), bullet2(1,10), bullet3(10,1), bullet4(10,10);
    scene->addItem(&bullet1);
    scene->addItem(&bullet2);
    scene->addItem(&bullet3);
    scene->addItem(&bullet4);

    Enemy e1(boardData,10,10);
    Enemy e2(boardData, 10, 4);
    scene->addItem(&e1);
    scene->addItem(&e2);




    //timer t;
    //scene->addItem(&t);



    //if (ame.d(e1, r))
       // e1.life--;

if (e1.life ==0 && e2.life ==0){
    QPixmap image("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\catangry.png");
    image = image.scaledToWidth(60);
    image = image.scaledToHeight(60);
    //setPixmap(image);
}


    view->setScene(scene);
    view->show();

    //return a.exec();
    return a.exec();


}

