#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

int dist[110][110];
map <int, int> mm;

int small(int a, int b)
{
    return (a < b) ? a : b;
}

void floyd(int node)
{
    int i, j, k;
    for(i = 1; i <= node; ++i)
        for(j = 1; j <= node; ++j)
            for(k = 1; k <= node; ++k)
                dist[j][k] = small(dist[j][k], dist[j][i] + dist[i][k]);
}

int main()
{
    int i, j, k, a, b, cnt = 0;
    double value, x;
    while(scanf("%d %d", &a, &b) == 2)
    {
        if(a == 0 && b == 0)
            break;

        i = 0;
        mm[a] = ++i;
        mm[b] = ++i;
        dist[mm[a]][mm[b]] = 1;
        while(scanf("%d %d", &a, &b) == 2)
        {
            if(a == 0 && b == 0)
                break;
            if(mm.find(a) == mm.end())
                mm[a] = ++i;
            if(mm.find(b) == mm.end())
                mm[b] = ++i;
            dist[mm[a]][mm[b]] = 1;
        }

        for(j = 1; j <= i; ++j)
        {
            for(k = 1; k <= i; ++k)
            {
                if(dist[j][k] == 0)
                dist[j][k] = 99999999;
            }
            dist[j][j] = 0;
        }

        floyd(i);
        value = 0;
        for(j = 1; j <= i; ++j)
            for(k = 1; k <= i; ++k)
            {
                value += dist[j][k];
                dist[j][k] = 0;
            }
        x = i * (i - 1);
//            printf("%lf %lf", value, x);
        printf("Case %d: average length between pages = %.3lf clicks\n", ++cnt, value / x);
        mm.clear();
    }
    return 0;
}
