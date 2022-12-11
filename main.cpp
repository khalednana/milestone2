#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include "bullet.h"
#include "player.h"
#include "food.h"
#include "enemy.h"
#include "heart.h"
#include <QDir>
#include <QDebug>
#include <QVector>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView view;
    QGraphicsScene scene;

    //qDebug() << "here"; // You can use this for tracing

    view.setFixedSize(650, 650);
    view.setWindowTitle("Maze Game");
    QBrush brush(Qt::black);
    view.setBackgroundBrush(brush);

    QFile file("/Users/khalednana/Desktop/project/Board.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    int boardData[11][11];
    QString temp;
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
        {
            stream >> temp;
            boardData[i][j] = temp.toInt();
        }


    QPixmap grassImage("/Users/khalednana/Desktop/project/concrete.jpeg");
    grassImage = grassImage.scaledToWidth(50);
    grassImage = grassImage.scaledToHeight(50);

    QPixmap bricksImage("/Users/khalednana/Desktop/project/sandwall2.jpeg");
    bricksImage = bricksImage.scaledToWidth(50);
    bricksImage = bricksImage.scaledToHeight(50);

    QPixmap HouseImage("/Users/khalednana/Desktop/project/house.jpeg");
    HouseImage = HouseImage.scaledToWidth(50);
    HouseImage = HouseImage.scaledToHeight(50);


    QGraphicsPixmapItem boardItems[11][11];
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
        {
            // Set Image
            if (boardData[i][j] < 0)
                boardItems[i][j].setPixmap(bricksImage);
            else
            boardItems[i][j].setPixmap(grassImage);

            // Set Position
            boardItems[i][j].setPos(50 + j * 50, 50 + i * 50);

            // Add to the Scene
            scene.addItem(&boardItems[i][j]);
        }

    Player player(boardData);
    scene.addItem(&player);
    player.h[0].setPos(500,75);
    scene.addItem(&player.h[0]);
    player.h2[0].setPos(525,75);
    player.h3[0].setPos(550,75);
    scene.addItem(&player.h2[0]);
    scene.addItem(&player.h3[0]);
    scene.addItem(&player.m1);
    scene.addItem(&player.m2);

    Food food,food2;
    food.setPos(100, 250);
    food2.setPos(250, 100);
    scene.addItem(&food);
    scene.addItem(&food2);


    bullet bullet,bullet2,bullet3,bullet4;
    bullet.setPos(110, 110);
    bullet2.setPos(500,500);
    bullet3.setPos(500,110);
    bullet4.setPos(110,500);

    scene.addItem(&bullet);
    scene.addItem(&bullet2);
    scene.addItem(&bullet3);
    scene.addItem(&bullet4);
    bullet.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    bullet.setFocus();

    heart h[3];
    h[0].setPos(500,75);



    player.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player.setFocus();

    view.setScene(&scene);
    view.show();


    return a.exec();
}
