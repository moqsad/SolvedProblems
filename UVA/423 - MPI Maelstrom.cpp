#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <vector>
using  namespace std;

vector <int> edge[110];
vector <int> cost[110];

int d[110];

struct data
{
    int city, dist;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

priority_queue <data> Q;

void dijkstra(int n)
{
    int i, x, y;
    data u, v;
    for(i = 1; i < n; ++i)
        d[i] = 1000000000;
    u.city = 0;
    u.dist = 0;
    Q.push(u);
    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();
        y = u.city;
        x = edge[y].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge[y][i];
            v.dist = cost[y][i] + d[y];
            if(v.dist < d[v.city])
            {
                d[v.city] = v.dist;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int n, i, j, a, b, total;
    char arr[110];
    while(scanf("%d", &n) == 1)
    {
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < i; ++j)
            {
                scanf("%s", arr);
                if(arr[0] != 'x')
                {
                    b = atoi(arr);
                    cost[i].push_back(b);
                    cost[j].push_back(b);
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }

        dijkstra(n);

        total = 0;
        for(i = 0; i < n; ++i)
        {
            if(d[i] > total)
                total = d[i];
            cost[i].clear();
            edge[i].clear();
        }
        printf("%d\n", total);
    }
    return 0;
}
