#include "graph.h"

Graph::Graph(int data[11][11])
{
    QVector<QVector<int>> Adj;

    Adj.resize(121);
for(int i=0;i<11;i++)
{
    for(int j=0;j<11;j++)
    {
        int u;
        u=(i*11)+j;
        if(data[i][j]>0)
        {
            if(data[i+1][j]>0)
            {
                int v=((i+1)*11)+j;
                Adj[u].push_back(v);
            }
            if(data[i-1][j]>0)
            {
                int v=((i-1)*11)+j;
                Adj[u].push_back(v);
            }
            if(data[i][j+1]>0)
            {
                int v=((i)*11)+(j+1);
                Adj[u].push_back(v);
            }
            if(data[i][j-1]>0)
            {
                int v=((i)*11)+(j-1);
                Adj[u].push_back(v);
            }

        }

    }
}
for(int i=0;i<225;i++)
{
    QVector<int> nbr=Adj[i];
    for(int j=0;j<225;j++)
    {
        int n = nbr.indexOf(j);
        if(n!=-1)
        {
            adj_matrix[i].push_back(1);
            matrix[i][j]=1;
        }
        else
        {
            adj_matrix[i].push_back(0);
            matrix[i][j]=1;
        }
    }
}
}

QVector<QVector<int>> Graph::Dijkstra(int Graph[15][15], int startVertex)
{

        bool done[N];
        int previous[N];
        double cost[N];

        double temp[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (Graph[i][j] == 0)
                    temp[i][j] = INF;
                else
                    temp[i][j] = Graph[i][j];

        // 1st Row:
        for (int i = 0; i < N; i++)
        {
            if (i == startVertex)
            {
                done[i] = true;
                previous[i] = -1;
                cost[i] = 0;
            }
            else
            {
                done[i] = false;
                previous[i] = startVertex;
                cost[i] = temp[startVertex][i];
            }
        }
        // Today
        int count = 1;
        while (count < N)
        {
            // Which vertex is done?
            // Vertex with the lowest cost.
            double minimum = INF;
            int currentVertex;
            for (int i = 0; i < N; i++)
            {
                if (done[i] == false && cost[i] < minimum)
                {
                    minimum = cost[i];
                    currentVertex = i;
                }
            }
            done[currentVertex] = true;
            //
            for (int i = 0; i < N; i++)
            {
                if (done[i] == false)
                {
                    double value = cost[currentVertex] + temp[currentVertex][i];
                    if (value < cost[i])
                    {
                        cost[i] = value;
                        previous[i] = currentVertex;
                    }
                }
            }
            count++;
        }
        QVector<QVector<int>> paths;
        paths.resize(N);
        int j;
        for (int i = 0; i < N; i++)
        {
            paths[i].push_back(i);
            j = i;
            while (j != startVertex)
            {
                paths[i].insert(paths[i].begin(), previous[j]);
                j = previous[j];
            }
        }
        return paths;
    }

