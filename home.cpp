#include "home.h"

home::home(int row, int col)
{
    QPixmap homeimage("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\B01.png");
        homeimage = homeimage.scaledToWidth(50);
        homeimage = homeimage.scaledToHeight(50);
        setPixmap(homeimage);
        setPos(50 + col * 50, 50 + row * 50);
}
