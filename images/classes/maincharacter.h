#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


class maincharacter : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
   int row, column;
   int data [12][12];
   maincharacter(int boardData[12][12]);
public slots:
   void keyPressEvent(QKeyEvent* event);
};
#endif // MAINCHARACTER_H
