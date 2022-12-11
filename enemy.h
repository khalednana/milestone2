#ifndef ENEMY_H
#define ENEMY_H

#include "graph.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include <QRandomGenerator>
class enemy : public QObject, public QGraphicsPixmapItem
{
public:
    enemy();
    int row, column;
    bool f;
    bool hitPlayer;
    int m[121][121];
    int health;
    //Graph Grph;
public slots:
    void movement();
    void initialize(int boardData[11][11]);
    void Matrix();
    QVector<QVector<int>> Dijkstra(int startVertex);
    void jvjgnvjkhg();

private:
    QVector<QVector<int>> matrix;

    int data[11][11];

   QTimer *timer;
   QRandomGenerator generator;
private slots:



};

#endif // ENEMY_H
