#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include<sstream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;//ACCEPTED............

double d[210];
vector <double> cost[210];
vector <long long int> edge[210];
long long int n;
string arr;
char letter[100];

struct data
{
    long long int city;
    double dist;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

void dijkstra(void)
{
    long long int i, x, y;
    data u, v;
    priority_queue <data> Q;
    for(i = 0; i < n; ++i)
    {
        d[i] = 100000000000.0;
    }

    u.city = 0;
    u.dist = 0.0;
    Q.push(u);
    d[0] = 0.0;

    while(!Q.empty())
    {
        u = Q.top();
        if(u.city == 1)
            return;
        Q.pop();
        x = edge[u.city].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge[u.city][i];
            v.dist = d[u.city] + cost[u.city][i];
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
    long long int cnt, i, j, x, t, a[2100], b[2100];
    double y, z, p;
    scanf("%lld\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld %lld %lld", &a[0], &b[0], &a[1], &b[1]);
        getchar();

        n = 2;

        string line;
        while(getline(cin, line) && line.size()>0)
        {
            stringstream sin (line);
            int kount = 0;
            while(sin>>a[n]>>b[n])
            {
                if(a[n]==-1 && b[n]==-1)
                    break;
                if(kount>0)
                {
                    double bal = sqrt((a[n-1]-a[n])*(a[n-1]-a[n]) + (b[n-1]-b[n])*(b[n-1]-b[n])) * .0015;
                    cost[n-1].push_back(bal);
                    cost[n].push_back(bal);
                    edge[n].push_back(n-1);
                    edge[n-1].push_back(n);
                }
                n++;
                kount++;
            }
        }


        for(i = 0; i < n; ++i)
            for(j = i + 1; j  < n; ++j)
            {
                y = a[i] - a[j];
                z = b[i] - b[j];
                p = sqrt(y * y  + z * z) * .006;
                cost[i].push_back(p);
                cost[j].push_back(p);
                edge[i].push_back(j);
                edge[j].push_back(i);
            }

        dijkstra();

        printf("%.0lf\n", d[1]);
        if(cnt < t)
            printf("\n");
        for(i = 0; i < n; ++i)
        {
            cost[i].clear();
            edge[i].clear();
        }
    }
    return 0;
}

/*
1

0 0 0 10000
0 0 0 5000 -1 -1
0 5000 0 10000 -1 -1
*/


