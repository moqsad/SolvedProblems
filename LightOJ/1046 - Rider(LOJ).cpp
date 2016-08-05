#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;

queue <int> qr, qc;

int visit[12][12], dist[12][12], n, m, p[] = {1, 1, 2, 2, -1, -1, -2, -2}, q[] = {2, -2, 1, -1, 2, -2, 1, -1};

char arr[12][12];

void bfs(int r, int c)
{
    int i, j, u, v;

    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
        {
            dist[i][j] = -1;
            visit[i][j] = 0;
        }

    qr.push(r);
    qc.push(c);

    visit[r][c] = 1;
    dist[r][c] = 0;

    while(!qr.empty())
    {
        r = qr.front();
        c = qc.front();

        qr.pop();
        qc.pop();

        for(i = 0; i < 8; ++i)
        {
            u = r + p[i];
            v = c + q[i];

            if(u >= 0 && u < n && v >= 0 && v < m && !visit[u][v])
            {
                visit[u][v] = 1;
                dist[u][v] = dist[r][c] + 1;
                qr.push(u);
                qc.push(v);
            }
        }
    }
}

int main()
{
    int t, cnt, p, i, j, k, l, min_, sum, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);

        for(i = 0; i < n; ++i)
            scanf("%s", arr[i]);

        min_ = 1000000000;
        p = 0;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < m; ++j)
            {
                bfs(i, j);
                sum = 0;
                for(k = 0; k < n; ++k)
                {
                    for(l = 0; l < m; ++l)
                    {
                        if(arr[k][l] != '.')
                        {
                            if(dist[k][l] != -1)
                            {
                                x = arr[k][l] - 48;
                                sum += dist[k][l] / x;
                                if(dist[k][l] % x > 0)
                                    sum += 1;
                            }
                            else
                                break;
                        }
                    }
                    if(l < m)
                        break;
                }
                if(k == n)
                {
                    p = 1;
                    min_ = min(min_, sum);
                }
            }
        }

        if(p == 1)
            printf("Case %d: %d\n", cnt, min_);
        else
            printf("Case %d: -1\n", cnt);
    }
    return 0;
}

