#include "home.h"

Home::Home()
{
    QPixmap image("/Users/khalednana/Desktop/project/finalhouse.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    setPos(50 + 5 * 50, 50 + 5 * 50);
}
