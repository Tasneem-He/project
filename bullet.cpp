#include "bullet.h"

bullet::bullet(int row, int col)
{
    QPixmap image1 ("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\Pistol.png");
    image1=image1.scaledToHeight(50);
    image1=image1.scaledToWidth(50);
    setPixmap(image1);
    setPos(50 + col * 50, 50 + row * 50);



}
