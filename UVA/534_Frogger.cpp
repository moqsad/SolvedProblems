#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int par[210], visit[210], det;
double a[210], b[210], total;

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

struct data
{
    int u, v;
    double w;
};

vector <data> road;
vector <double> value[210];
vector <int> arr[210];

bool comp(data p, data q)
{
    return p.w < q.w;
}

void dfs(int x)
{
    int j, i;
    j = arr[x].size();
    for(i = 0; i < j; ++i)
    {
        if(visit[arr[x][i]] == 0)
        {
            visit[arr[x][i]] = 1;
            if(arr[x][i] == 1)
            {
                det = 1;
                if(total < value[x][i])
                    total = value[x][i];
                return;
            }

            dfs(arr[x][i]);

            if(det == 1)
            {
                if(total < value[x][i])
                    total = value[x][i];
                return;
            }
        }
    }
    return;
}

int main()
{
    int cnt = 0, i, j, k, c, x, n, y;
    double p, q;
    data info;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        road.clear();
        for(i = 0; i < n; ++i)
        {
            visit[i] = 0;
            par[i] = i;
            scanf("%lf %lf", &a[i], &b[i]);
        }
        x = n - 1;
        for(i = 0; i < x; ++i)
            for(j = i + 1; j < n; ++j)
            {
                p = a[i] - a[j];
                q = b[i] - b[j];
                info.u = i;
                info.v = j;
                info.w = sqrt(p * p + q * q);
                //printf("%.3lf\n", info.w);
                road.push_back(info);
            }
        sort(road.begin(), road.end(), comp);
        j = 0;
        c = road.size();
        k = n - 1;
        int g, h;
        for(i = 0; i < c; ++i)
        {
            g = road[i].u;
            h = road[i].v;
            x = func(g);
            y = func(h);
            if(x != y)
            {
                par[x] = y;
                arr[g].push_back(h);
                arr[h].push_back(g);
                value[g].push_back(road[i].w);
                value[h].push_back(road[i].w);
                //printf("%d %d__\n", g, h);
                ++j;
                if(j == k)
                    break;
            }
        }
        total = 0;
        det = 0;
        visit[0] = 1;
        dfs(0);
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", ++cnt, total);
        for(i = 0; i < n; ++i)
        {
            arr[i].clear();
            value[i].clear();
        }
    }
    return 0;
}
/*
4
0 0
4 4
1 1
2 2
*/
