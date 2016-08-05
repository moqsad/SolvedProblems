#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector <int> edge[110];
vector <int> cost[110];

int d[110], N;

struct data
{
    int city, dist;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

void dijkstra(int start)
{
    int i, x;
    for(i = 1; i <= N; ++i)
        d[i] = 2147483645;
    priority_queue <data> Q;
    data u, v;
    u.city = start;
    u.dist = 0;
    Q.push(u);
    d[start] = 0;
    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();
        x = edge[u.city].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge[u.city][i];
            v.dist = cost[u.city][i] + d[u.city];
            if(d[v.city] > v.dist)
            {
                d[v.city] = v.dist;
                Q.push(v);
            }
        }
    }
    return;
}

int main()
{
    int t, cnt, i, a, b, c, M, E, T, ans;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d %d", &N, &E, &T, &M);
        for(i = 0; i < M; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[b].push_back(a);
            cost[b].push_back(c);
        }
        dijkstra(E);
        ans = 0;
        for(i = 1; i <= N; ++i)
        {
            if(d[i] <= T)
                ++ans;
            edge[i].clear();
            cost[i].clear();
        }
        printf("%d\n", ans);
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
