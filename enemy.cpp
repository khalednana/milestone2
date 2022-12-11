#include "enemy.h"
#include "player.h"
#include <QTimer>
#include <qglobal.h>
#include <QRandomGenerator>
#include "QtCore/qobjectdefs.h"
extern Player p;

enemy::enemy()
{

    // Set Image
    QPixmap image("/Users/khalednana/Desktop/project/strongmichael.png");
    image = image.scaledToWidth(70);
    image = image.scaledToHeight(70);
    setPixmap(image);

    // Set Position
    row = 9;
    column = 8;
    setPos(50 + column * 50, 50 + row * 50);
    health=2;

    hitPlayer=false;
    // Set data Array


    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&enemy::movement);
    timer->start(250);

}
void enemy::movement()
{

        if(health==1 && f==true)
        {
            QPixmap image("/Users/khalednana/Desktop/project/ene.png");
            image = image.scaledToWidth(70);
            image = image.scaledToHeight(70);
            setPixmap(image);
        }
        if(health==1 && f==false)
        {
            QPixmap image("/Users/khalednana/Desktop/project/weakTrevor.png");
            image = image.scaledToWidth(70);
            image = image.scaledToHeight(70);
            setPixmap(image);
        }

        int x;
        x=generator.bounded(1, 5);
        if(f==true){
            if (x != 2 && x !=3 && x != 4 && data[row - 1][column] >= 0 )
            {
            row--;
            setPos(50 + column * 50, 50 + row * 50);
            }
           if (x != 1 && x !=3 && x != 4 && data[row + 1][column] >= 0)
            {
               row ++;
               setPos(50 + column * 50, 50 + row * 50);
            }

           if (x != 1 && x !=2 && x != 4 && data[row][column + 1] >= 0)
           {
               column++;
               setPos(50 + column * 50, 50 + row * 50);

           }
           if (x != 1 && x != 2 && x != 3 && data[row][column - 1] >= 0)
           {
               column--;
               setPos(50 + column * 50, 50 + row * 50);
           }
        }
        if(f==false){
        if (x != 1 && x !=3 && x != 4 && data[row - 1][column] >= 0)
        {
        row--;
        setPos(50 + column * 50, 50 + row * 50);
        }
        else if (x != 2 && x !=3 && x != 4 && data[row + 1][column] >= 0)
        {
               row ++;
               setPos(50 + column * 50, 50 + row * 50);
        }
        else if (x != 1 && x !=2 && x != 3 && data[row][column + 1] >= 0)
               {
                   column++;
                   setPos(50 + column * 50, 50 + row * 50);

               }
        else if (x != 1 && x != 2 && x != 4 && data[row][column - 1] >= 0)
               {
                   column--;
                   setPos(50 + column * 50, 50 + row * 50);
               }
    }


    QList<QGraphicsItem*> items = collidingItems();
    for (int i = 0; i < items.size(); i++)
    {
        if (typeid(*items[i]) == typeid(Player)) {
           hitPlayer=true;
           }
    }
}

void enemy::initialize(int boardData[11][11])
{
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
            data[i][j] = boardData[i][j];
    if(f==false)
    {
        row = 9;
        column = 2;
        setPos(50 + column * 50, 50 + row * 50);
        QPixmap image("/Users/khalednana/Desktop/project/trevor.png");
        image = image.scaledToWidth(70);
        image = image.scaledToHeight(70);
        setPixmap(image);

    }

}

//void enemy::Matrix()
//{
//    int u,y;
//    QVector<QVector<int>> Adj;
//    Adj.resize(121);


//    for (int i = 0; i < 11; i++) {
//        for (int j = 0; j < 11; j++) {
//            u=(i*11)+j;
//            if(data[i][j] != -1)
//            {
//                if(data[i][j+1] != -1)
//                {
//                    y=(i*11)+(j+1);
//                    qDebug()<<y;
//                    Adj[u].push_back(y);
//                }
//                if(data[i][j-1] != -1)
//                {
//                    y=(i*11)+(j-1);
//                    qDebug()<<y;
//                    Adj[u].push_back(y);
//                }
//                if(data[i+1][j] != -1)
//                {
//                    y=(i+1)+(j*11);
//                    qDebug()<<y;
//                    Adj[u].push_back(y);

//                }
//                if(data[i-1][j] != -1)
//                {
//                    y=(i-1)+(j*11);
//                    qDebug()<<y;
//                    Adj[u].push_back(y);

//                }
//            }

//        }
//    }
////     QVector<QVector<int>> matrix;
//     matrix.resize(121);
//    for (int i = 0; i < 121; i++)
//    {
//        QVector<int> nbr=Adj[i];
//        for(int j=0;j<121;j++)
//        {
//            int n=nbr.indexOf(j);
//            if(n!=-1)
//            {
//                matrix[i].push_back(1);
//            }
//            else
//            {
//                 matrix[i].push_back(0);
//            }
//        }
//    }
////    int m[121][121];
//    for (int i = 0; i < 121; i++)
//    {
//        for(int j=0;j<121;j++)
//        {
//            m[i][j] = matrix[i][j];
//        }
//    }

//}



//QVector<QVector<int>> enemy::Dijkstra(int startVertex)
//{
//    int N=11;
//    bool done[N];
//    int previous[N];
//    double cost[N];

//    int INF = 9999;
//    double temp[N][N];
//    for (int i = 0; i < N; i++)
//        for (int j = 0; j < N; j++)
//            if (m[i][j] == 0)
//                temp[i][j] = INF;
//            else
//                temp[i][j] = m[i][j];

//    // 1st Row:
//    for (int i = 0; i < N; i++)
//    {
//        if (i == startVertex)
//        {
//            done[i] = true;
//            previous[i] = -1;
//            cost[i] = 0;
//        }
//        else
//        {
//            done[i] = false;
//            previous[i] = startVertex;
//            cost[i] = temp[startVertex][i];
//        }
//    }
//    // Today
//    int count = 1;
//    while (count < N)
//    {
//        // Which vertex is done?
//        // Vertex with the lowest cost.
//        double minimum = INF;
//        int currentVertex;
//        for (int i = 0; i < N; i++)
//        {
//            if (done[i] == false && cost[i] < minimum)
//            {
//                minimum = cost[i];
//                currentVertex = i;
//            }
//        }
//        done[currentVertex] = true;
//        //
//        for (int i = 0; i < N; i++)
//        {
//            if (done[i] == false)
//            {
//                double value = cost[currentVertex] + temp[currentVertex][i];
//                if (value < cost[i])
//                {
//                    cost[i] = value;
//                    previous[i] = currentVertex;
//                }
//            }
//        }
//        count++;
//    }
//    QVector<QVector<int>> paths;
//    paths.resize(N);
//    int j;
//    for (int i = 0; i < N; i++)
//    {
//        paths[i].push_back(i);
//        j = i;
//        while (j != startVertex)
//        {
//            paths[i].insert(paths[i].begin(), previous[j]);
//            j = previous[j];
//        }
//    }
//    return paths;
//}

//void enemy::jvjgnvjkhg()
//{
//    int z=(3*11)+9;
//    QVector<QVector<int>> results=Grph.Dijkstra(matrix,z);
//}


