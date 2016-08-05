#include "bits/stdc++.h"
using namespace std;

#define SZ 1100

bool matrix[SZ][SZ];
bool vis[SZ][SZ];
int dist[SZ][SZ], start_row, start_column, finish_row, finish_column, n, m;

queue <int> Qrow;
queue <int> Qcolumn;

void BFS(void)
{
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    while(!Qrow.empty())
    {
        Qrow.pop();
        Qcolumn.pop();
    }

    vis[start_row][start_column] = 1;
    Qrow.push(start_row);
    Qcolumn.push(start_column);

    int x, u, v;

    while(!Qrow.empty())
    {
        u = Qrow.front();
        v = Qcolumn.front();
        Qrow.pop();
        Qcolumn.pop();

        x = v - 1;
        if(x >= 0 && vis[u][x] == 0 && matrix[u][x] == 0)
        {
            vis[u][x] = 1;
            dist[u][x] = dist[u][v] + 1;
            if(u == finish_row && x == finish_column)
                break;
            Qrow.push(u);
            Qcolumn.push(x);
        }

        x = v + 1;
        if(x < m && vis[u][x] == 0 && matrix[u][x] == 0)
        {
            vis[u][x] = 1;
            dist[u][x] = dist[u][v] + 1;
            if(u == finish_row && x == finish_column)
                break;
            Qrow.push(u);
            Qcolumn.push(x);
        }

        x = u - 1;
        if(x >= 0 && vis[x][v] == 0 && matrix[x][v] == 0)
        {
            vis[x][v] = 1;
            dist[x][v] = dist[u][v] + 1;
            if(x == finish_row && v == finish_column)
                break;
            Qrow.push(x);
            Qcolumn.push(v);
        }

        x = u + 1;
        if(x < n && vis[x][v] == 0 && matrix[x][v] == 0)
        {
            vis[x][v] = 1;
            dist[x][v] = dist[u][v] + 1;
            if(x == finish_row && v == finish_column)
                break;
            Qrow.push(x);
            Qcolumn.push(v);
        }
    }
    return ;
}

int main()
{
    int i, j, k, row, column, x, y;

    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
            break;
        memset(matrix, 0, sizeof(matrix));
        scanf("%d", &x);
        for(i = 0; i < x; ++i)
        {
            scanf("%d %d", &row, &y);
            for(j = 0; j < y; ++j)
            {
                scanf("%d", &column);
                matrix[row][column] = -1;
            }
        }
        scanf("%d %d %d %d", &start_row, &start_column, &finish_row, &finish_column);
        BFS();
        printf("%d\n", dist[finish_row][finish_column]);
    }
    return 0;
}

/*
10 10
9
0 1 2
1 1 2
2 2 2 9
3 2 1 7
5 3 3 6 9
6 4 0 1 2 7
7 3 0 3 8
8 2 7 9
9 3 2 3 4
0 0
9 9
*/
