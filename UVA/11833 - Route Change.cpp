#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int num[500], d[500], n, m, c, k;

vector <int> edge[500];
vector <int> cost[500];

struct data
{
    int city, dist;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

priority_queue <data> q;

void dijkstra(int start)
{
    int i, j, x, y;
    data u, v;

    for(i = 0; i < n; ++i)
        d[i] = 1000000000;

    d[start] = 0;

    u.dist = 0;
    u.city = start;
    q.push(u);

    while(!q.empty())
    {
        u = q.top();
        q.pop();
        y = u.city;
        x = edge[y].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge[y][i];
            v.dist = cost[y][i] + u.dist;
            if(v.dist < d[v.city])
            {
                d[v.city] = v.dist;
                if(v.city >= c)
                    q.push(v);
            }
        }
    }
}

int main()
{
    int u, v, p, cnt, t, i, x, total;
    while(scanf("%d %d %d %d", &n, &m, &c, &k) == 4)
    {
        if(n == 0 && m == 0 && c == 0 && k == 0)
            break;
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &u, &v, &p);

            if(u > v && u < c && u - v == 1)
                num[u] = p;
            else if(v > u && v < c && v - u == 1)
                num[v] = p;
            else if(!(u < c && v < c))
            {
                edge[u].push_back(v);
                edge[v].push_back(u);
                cost[u].push_back(p);
                cost[v].push_back(p);
            }
        }

        num[0] = 0;
        for(i = 1; i < c; ++i)
            num[i] += num[i - 1];

        x = c - 1;

        for(i = 0; i < c; ++i)
            num[i] = num[x] - num[i];

        dijkstra(k);
        total = 1000000000;
        for(i = 0; i < c; ++i)
        {
            x = d[i] + num[i];
            if(x < total)
                total = x;
        }

        printf("%d\n", total);
        for(i = 0; i < n; ++i)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
/*
4 3 3 3
1 2 10
1 3 10
3 0 1

7 8 4 4
4 5 1
0 5 1
5 6 100
0 6 1
0 1 10
1 2 10
2 3 10
3 6 5
*/


