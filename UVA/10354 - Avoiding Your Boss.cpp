#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int d[105], cost[105][105], par[105][105], P, count_[105];

struct data
{
    int dist, city;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

void func(int x)
{
    int y, i;
    d[x] = -1;
    y = count_[x];

    for(i = 1; i <= y; ++i)
    {
        func(par[x][i]);
    }
}

void dijkstra(int start, int finish)
{
    int i, z;

    if(d[start] != -1)
    {
        d[start] = 0;
        count_[start] = 0;

        priority_queue <data> q;
        data u, v;
        u.dist = 0;
        u.city = start;
        q.push(u);

        while(!q.empty())
        {
            u = q.top();

            if(u.city == finish)
                break;

            q.pop();

            for(i = 1; i <= P; ++i)
            {
                if(d[i] != -1 && cost[u.city][i] > -1)
                {
                    v.city = i;
                    v.dist = d[u.city] + cost[u.city][i];

                    if(v.dist < d[v.city])
                    {
                        d[v.city] = v.dist;
                        q.push(v);
//                        z = 1;
                        par[v.city][1] = u.city;
                        count_[v.city] = 1;
                    }

                    else if(v.dist < 1000000000 && v.dist == d[v.city])
                    {
                        ++count_[v.city];
                        par[v.city][count_[v.city]] = u.city;
                    }
                }
            }
        }
    }
}

int main()
{
    int R, BH, OF, YH, M, i, a, b, c;
    while(scanf("%d %d %d %d %d %d", &P, &R, &BH, &OF, &YH, &M) == 6)
    {
        memset(cost, -1, sizeof(cost));
        for(i = 0; i < R; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            cost[a][b] = c;
            cost[b][a] = c;
        }

        for(i = 1; i <= P; ++i)
            d[i] = 1000000000;

        dijkstra(BH, OF);

        func(OF);

        for(i = 1; i <= P; ++i)
            if(d[i] != -1)
                d[i] = 1000000000;

        dijkstra(YH, M);

        if(d[M] == 1000000000 || d[M] == -1)
            printf("MISSION IMPOSSIBLE.\n");
        else
            printf("%d\n", d[M]);
    }
    return 0;
}

/*
3 3 1 2 3 3
1 2 2
1 3 1
3 2 1

6 6 2 4 1 1
3 5 11
5 1 2
5 4 8
2 5 13
1 4 6
3 4 7

6 6 2 5 3 3
3 2 2
3 5 8
2 5 10
5 1 15
3 4 18
5 4 8

8 9 1 7 6 8
1 2 1
1 3 1
2 4 1
3 4 1
4 5 2
4 6 1
5 7 1
6 8 1
8 7 1
*/
