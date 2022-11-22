#include "lifestuff.h"

lifestuff::lifestuff(int row, int col)
{
    QPixmap image ("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\heart.png");
    image=image.scaledToHeight(50);
    image=image.scaledToWidth(50);
    setPixmap(image);
    setPos(50 + col * 50, 50 + row * 50);

}

void lifestuff::changeHeart(int row, int col)
{
   scene()->removeItem(this);






        QPixmap image("C:\\Users\\Tasnem\\Downloads\\CS2-Project\\images\\noheart.png");
        image = image.scaledToWidth(50);
        image = image.scaledToHeight(50);
        setPixmap(image);
        setPos(50 + col * 50, 50 + row * 50);



}
