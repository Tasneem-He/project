#ifndef GAME_H
#define GAME_H
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


class game : public QGraphicsView
{
public:
    game(QWidget * parent=0);




    float d(Enemy x, class::rect y);
};

#endif // GAME_H
