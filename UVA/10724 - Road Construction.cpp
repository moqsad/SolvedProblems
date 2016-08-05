#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define inf 1000000.0

int n;
double X[52], Y[52], cost[52][52], d[52][52], road[52][52], sum;

void floyd(void)
{
    int i, j, k;
    for(k = 1; k <= n; ++k)
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void func(int p, int q)
{
    int i, j, k;
    sum = 0;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
        {
            road[i][j] = min(min(road[i][j], road[i][p] + road[p][q] + road[q][j]), road[i][q] + road[p][q] + road[p][j]);
            sum += d[i][j] - road[i][j];
        }
}

int main()
{
    double total, dist, z;
    int u, v, m, i, j, k, l, a, b;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 &&  m == 0)
            break;

        for(i = 1; i <= n; ++i)
            scanf("%lf %lf", &X[i], &Y[i]);

        for(i = 1; i <= n; ++i)
            for(j = 1; j <= i; ++j)
            {
                z = sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
                cost[i][j] = z;
                cost[j][i] = z;
            }

        for(i = 1; i <= n; ++i)
        {
            for(j = 1; j <= i; ++j)
            {
                d[i][j] = inf;
                d[j][i] = inf;
            }
            d[i][i] = 0;
        }

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            d[a][b] = cost[a][b];
            d[b][a] = cost[a][b];
        }

        floyd();

        total = 0;
        dist = inf;

        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
            {
                if(i != j && cost[i][j] < d[i][j])
                {
                    for(k = 1; k <= n; ++k)
                        for(l = 1; l <= k; ++l)
                        {
                            road[k][l] = d[k][l];
                            road[l][k] = d[l][k];
                        }
                    road[i][j] = cost[i][j];
                    road[j][i] = cost[j][i];
                    func(i, j);
                    if(sum > total)
                    {
                        total = sum;
                        dist = cost[i][j];
                        u = i;
                        v = j;
                    }
                    else if(sum == total)
                    {
                        if(dist > cost[i][j])
                        {
                            dist = cost[i][j];
                            u = i;
                            v = j;
                        }

                        else if(dist == cost[i][j])
                        {
                            if(u > i)
                            {
                                u = i;
                                v = j;
                            }
                            else if(u == i && v > j)
                                v = j;
                        }
                    }
                }
            }

        if(total > 1)
            printf("%d %d\n", u, v);
        else
            printf("No road required\n");
    }
    return 0;
}
