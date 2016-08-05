#include <cstring>
#include <queue>
#include <iostream>
#include <cstdio>
using namespace std;

bool visit[25];
char arr[25][25];
int dist[25][25], startrow, startcolumn, p[] = {-1, 1, 0, 0}, q[] = {0, 0, -1, 1}, m, n;
queue <int> Qrow;
queue <int> Qcolumn;

void bfs(void)
{
    memset(dist, 0, sizeof(dist));
    Qrow.push(startrow);
    Qcolumn.push(startcolumn);
    int u, v, x, y, i;
    while(!Qrow.empty())
    {
        u = Qrow.front();
        v = Qcolumn.front();
        Qrow.pop();
        Qcolumn.pop();
        for(i = 0; i < 4; ++i)
        {
            x = u + p[i];
            y = v + q[i];
            if(x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#' && arr[x][y] != 'm')
            {
                arr[x][y] = '#';
                Qrow.push(x);
                Qcolumn.push(y);
                dist[x][y] = dist[u][v] + 1;
            }
        }
    }
}

int main()
{
    int t, i, j, k, total, x[5], y[5], cnt;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; ++i)
            scanf("%s", arr[i]);
        k = 0;
        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
            {
                if(arr[i][j] == 'a' || arr[i][j] == 'b' || arr[i][j] == 'c')
                {
                    x[k] = i;
                    y[k] = j;
                    ++k;
                }
                if(arr[i][j] == 'h')
                {
                    startrow = i;
                    startcolumn = j;
                }
            }
            bfs();
        total = 0;
        for(i = 0; i < k; ++i)
        {
            if(total < dist[x[i]][y[i]])
                total = dist[x[i]][y[i]];
        }
        printf("Case %d: %d\n", cnt, total);
    }
    return 0;
}

