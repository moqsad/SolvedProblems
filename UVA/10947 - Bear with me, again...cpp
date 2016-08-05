#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct data
{
    int city;
    double dist;

    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

double X[105], Y[105], R[105], d[105];
int cnt;

vector <int> edge[105];
vector <double> cost[105];

void dijkstra(void)
{
    int i, x;
    for(i = 1; i < cnt; ++i)
        d[i] = 1000000000;

    data u, v;
    d[1] = 0;
    u.dist = 0;
    u.city = 1;
    priority_queue <data> q;
    q.push(u);
    while(!q.empty())
    {
        u = q.top();
        if(u.city == 2)
            break;
        q.pop();
        x = edge[u.city].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge[u.city][i];
            v.dist = d[u.city] + cost[u.city][i];
            if(v.dist < d[v.city])
            {
                q.push(v);
                d[v.city] = v.dist;
            }
        }
    }
}

int main()
{
    int i, j, n;
    double K, M, z, dist;
    while(scanf("%lf %lf", &K, &M) == 2)
    {
        z = K * M;
        scanf("%lf %lf %lf", &X[1], &Y[1], &R[1]);
        scanf("%lf %lf %lf", &X[2], &Y[2], &R[2]);
        cnt = 3;
        scanf("%d", &n);

        for(i = 0; i < n; ++i)
        {
            scanf("%lf %lf %lf", &X[cnt], &Y[cnt], &R[cnt]);
            ++cnt;
        }

        for(i = 1; i < cnt; ++i)
        {
            for(j = 1; j < cnt; ++j)
            {
                if(i != j)
                {
                    dist = sqrt((X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
                    dist = dist - R[i] - R[j];
                    if(dist <= z)
                    {
                        edge[i].push_back(j);
                        cost[i].push_back(dist);
                    }
                }
            }
        }

        dijkstra();
        if(d[2] < 1000000000)
            printf("Larry and Ryan will escape!\n");
        else
            printf("Larry and Ryan will be eaten to death.\n");
        for(i = 1; i < cnt; ++i)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
