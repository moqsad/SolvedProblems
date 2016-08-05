#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;

int row, column, srow, scolumn, dist[2010][2010], arr[2010][2010], visit[2010][2010];

queue <int> Qrow;
queue <int> Qcolumn;

int BFS(void)
{
    memset(dist, 0, sizeof(dist));

    visit[srow][scolumn] = 1;
    int x, y;

    while(!Qrow.empty())
    {
        row = Qrow.front();
        column = Qcolumn.front();

        Qrow.pop();
        Qcolumn.pop();

        x = row;
        y = column - 1;

        if(x >= 0 && x <= 2000 && y >= 0 && y <= 2000 && visit[x][y] == 0)
        {
            dist[x][y] = dist[row][column] + 1;
            if(arr[x][y] == 1)
                return (dist[x][y]);
            visit[x][y] = 1;
            Qrow.push(x);
            Qcolumn.push(y);
        }

        x = row - 1;
        y = column;

        if(x >= 0 && x <= 2000 && y >= 0 && y <= 2000 && visit[x][y] == 0)
        {
            dist[x][y] = dist[row][column] + 1;
            if(arr[x][y] == 1)
                return (dist[x][y]);
            visit[x][y] = 1;
            Qrow.push(x);
            Qcolumn.push(y);
        }

        x = row;
        y = column + 1;

        if(x >= 0 && x <= 2000 && y >= 0 && y <= 2000 && visit[x][y] == 0)
        {
            dist[x][y] = dist[row][column] + 1;
            if(arr[x][y] == 1)
                return (dist[x][y]);
            visit[x][y] = 1;
            Qrow.push(x);
            Qcolumn.push(y);
        }

        x = row + 1;
        y = column;

        if(x >= 0 && x <= 2000 && y >= 0 && y <= 2000 && visit[x][y] == 0)
        {
            dist[x][y] = dist[row][column] + 1;
            if(arr[x][y] == 1)
                return (dist[x][y]);
            visit[x][y] = 1;
            Qrow.push(x);
            Qcolumn.push(y);
        }
    }
}

int main()
{
    int p, q, i, j;
    while(scanf("%d", &p) == 1)
    {
        if(p == 0)
            break;
        memset(visit, 0, sizeof(visit));
        memset(arr, 0, sizeof(arr));

        while(!Qrow.empty())
        {
            Qrow.pop();
            Qcolumn.pop();
        }

        scanf("%d %d", &srow, &scolumn);
        Qrow.push(srow);
        Qcolumn.push(scolumn);
        for(i = 1; i < p; ++i)
        {
            scanf("%d %d", &row, &column);
            visit[row][column] = 1;
            Qrow.push(row);
            Qcolumn.push(column);
        }
        scanf("%d", &q);
        for(j = 0; j < q; ++j)
        {
            scanf("%d %d", &row, &column);
            arr[row][column] = 1;
        }
        printf("%d\n", BFS());
    }
    return 0;
}
