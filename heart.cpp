#include "heart.h"

heart::heart()
{
    QPixmap image("/Users/khalednana/Desktop/project/heart.png");
    image = image.scaledToWidth(20);
    image = image.scaledToHeight(20);
    setPixmap(image);

}

