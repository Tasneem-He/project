#include "home.h"

home::home()
{
    QPixmap homeimage("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\B01.png");
        homeimage = homeimage.scaledToWidth(50);
        homeimage = homeimage.scaledToHeight(50);
        setPixmap(homeimage);

}
