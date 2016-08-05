#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

#define SZ 1000010

vector <int> edge[SZ];
vector <int> cost[SZ];
int arr[SZ];
int d[SZ];

struct data
{
    int city, dist;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

int dijkstra(int source, int destination)
{
    int i, p = 0;

    priority_queue <data> q;
    data u, v;
    u.city = source;
    u.dist = d[0];
    q.push(u);
    while(!q.empty())
    {
        u = q.top();
        q.pop();
        for(i = 0; i < edge[u.city].size(); ++i)
        {
            v.city = edge[u.city][i];
            v.dist = cost[u.city][i] + d[u.city];
            if(d[v.city] > v.dist)
            {
                d[v.city] = v.dist;
                if(v.city == destination)
                {
                    p = 1;
                    break;
                }
                q.push(v);
            }
        }
        if(p == 1)
            break;
    }
    return d[destination];
}

int main()
{
    int t, cnt, i, j, k, n, m, x, a;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        k = 0;
        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
            {
                scanf("%d", &arr[k++]);
            }
        int p[] = {-1, 1, -m, m};
        x = n * m;
        for(i = 0; i < x; ++i)
        {
            for(j = 0; j < 2; ++j)
            {
                a = i + p[j];
                if(a / m == i / m && a >= 0)
                {
                    edge[i].push_back(a);
                    cost[i].push_back(arr[a]);
                }
            }
            for(j = 2; j < 4; ++j)
            {
                a = i + p[j];
                if(a >= 0 && a < x)
                {
                    edge[i].push_back(a);
                    cost[i].push_back(arr[a]);
                }
            }
        }
        for(i = 0; i < x; ++i)
            d[i] = 2147483645;
        d[0] = arr[0];
        printf("%d\n", dijkstra(0, x - 1));
        for(i=0; i < x; i++)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
