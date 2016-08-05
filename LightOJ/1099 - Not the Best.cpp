#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int first[5510], second[5510];

struct data
{
    int dist, city;
    bool operator < (const data & p) const
    {
        return dist >  p.dist;
    }
};

vector <int> edge[5510], cost[5510];

void dijkstra(int n)
{
    int i, j, x, y;
    data u, v;
    for(i = 1; i <= n; ++i)
    {
        first[i] = 1000000000;
        second[i] = 1000000000;
    }
    priority_queue <data> q;
    u.city = 1;
    u.dist = 0;
    q.push(u);
    first[1] = 0;
    while(!q.empty())
    {
        u = q.top();
        q.pop();
        y = u.city;
        x = edge[y].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge[y][i];
            v.dist = cost[y][i] + first[y];
            if(v.dist != first[v.city])
            {
                if(v.dist < first[v.city])
                {
                    q.push(v);
//                    second[v.city] = first[v.city];
                    first[v.city] = v.dist;
                printf("%d %d %d %d__________\n", u.city, first[y], v.city, v.dist);
                }

                else if(v.dist < second[v.city])
                {
                    q.push(v);
                    second[v.city] = v.dist;
                printf("%d %d %d %d++++++++++\n", u.city, first[y], v.city, v.dist);
                }
            }

            v.dist = cost[y][i] + second[y];

            if(v.dist < second[v.city])
            {
                q.push(v);
                second[v.city] = v.dist;
                printf("%d %d %d %d***********\n", u.city, second[y], v.city, v.dist);
            }
        }
    }
}

int main()
{
    int cnt, n, m, t, i, j, x, a, b, c, total;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a].push_back(b);
            edge[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }

//        for(i = 1; i <= n; ++i)
//        {
//            x = edge[i].size();
//            total = 1000000000;
//            for(j = 0; j < x; ++j)
//            {
//                if(cost[i][j] < total)
//                    total = cost[i][j];
//            }
//        }

        dijkstra(n);
        for(i = 1; i <= n; ++i)
        {
            edge[i].clear();
            cost[i].clear();
        }
        printf("Case %d: %d\n", cnt, second[n]);
    }
    return 0;
}
/*
this is a sample input to understand why we should not break the dijkstra when we get the
expected node in the top of the queue
1
6 6
1 2 70
1 4 60
2 3 70
4 5 10
5 6 80
3 6 50
________

input
1
5 5
1 2 9
2 3 1
3 5 5
1 4 13
4 5 1

correct output
15
but ei coder output
16

______
again............
1
5 5
1 2 9
2 3 1
3 5 5
1 4 13
4 5 1

correct output
15
but ei coder output //coder fault thaka sotteo correct output dicche......
15


*/
