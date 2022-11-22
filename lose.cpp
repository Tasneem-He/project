#include "lose.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
lose::lose()
{
    QPixmap limage("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\lose.png");
        limage = limage.scaledToWidth(500);
        limage =limage.scaledToHeight(500);
        setPixmap(limage);
}
