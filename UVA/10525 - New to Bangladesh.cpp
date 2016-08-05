#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int totaltime[300][300], dist[300][300];

int small(int a, int b)
{
    return (a < b) ? a : b;
}

void floyd(int n)
{
    int i, j, k, x, y;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
            for(k = 1; k <= n; ++k)
            {
                x = totaltime[j][k];
                y = totaltime[j][i] + totaltime[i][k];
                if(y < x)
                {
                    totaltime[j][k] = y;
                    dist[j][k] = dist[j][i] + dist[i][k];
                }
                else if(x == y)
                {
                    dist[j][k] = small(dist[j][k], dist[j][i] + dist[i][k]);
                }
            }
}

int main()
{
    int i, j, k, cnt, t, n, m, a, b, c, d, q, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 1; i <= n; ++i)
        {
            for(j = i + 1; j <= n; ++j)
            {
                totaltime[i][j] = 100000100;
                totaltime[j][i] = 100000100;
                dist[i][j] = 100000100;
                dist[j][i] = 100000100;
            }
        }

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            if(totaltime[a][b] > c)
            {
                totaltime[a][b] = c;
                totaltime[b][a] = c;
                dist[a][b] = d;
                dist[b][a] = d;
            }
            else if(totaltime[a][b] ==  c)
            {
                x = small(dist[a][b], d);
                dist[a][b] = x;
                dist[b][a] = x;
            }
        }

        floyd(n);

        scanf("%d", &q);
        for(i = 0; i < q; ++i)
        {
            scanf("%d %d", &a, &b);
            if(totaltime[a][b] == 100000100)
                printf("No Path.\n");
            else
                printf("Distance and time to reach destination is %d & %d.\n", dist[a][b], totaltime[a][b]);
        }
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
