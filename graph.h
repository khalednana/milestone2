#ifndef GRAPH_H
#define GRAPH_H

#include <QVector>
class Graph
{
public:

    Graph(int data[11][11]);
    QVector<int> adj_matrix[121];
    int matrix[121][9];
    QVector<QVector<int>> Dijkstra(int arr[15][15], int startVertex);
    int N=11;
    int INF=9999;
};

#endif // GRAPH_H
