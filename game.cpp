#include "game.h"

game::game(QWidget *parent)
{

}
float game::d(Enemy x, class::rect y)
{
    float distance, tempx, tempy;
        tempx = (x.x() - y.x());
        tempx = tempx * tempx;
        tempy = (x.y() - y.y());
        tempy = tempy * tempy;
        distance = tempx + tempy;
        distance = sqrt(distance);
        return distance;

}
