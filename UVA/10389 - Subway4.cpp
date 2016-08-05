#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std; //ACCEPTED...............

double d[2100];
vector <double> cost[2100];
vector <long long int> edge[2100];
long long int n, finish;
string arr;
char letter[100000];

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
        d[i] = 214748364500.0;

    u.city = 0;
    u.dist = 0.0;
    Q.push(u);
    d[0] = 0.0;

    while(!Q.empty())
    {
        u = Q.top();
        if(u.city == 1)
            break;
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
    long long int cnt, i, j, x, m, t, a[2100], b[2100];
    double y, z, p;
    scanf("%lld\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld %lld %lld", &a[0], &b[0], &a[1], &b[1]);
        double bal = sqrt((a[0]-a[1])*(a[0]-a[1])+(b[0]-b[1])*(b[0]-b[1]))*.006;
        cost[0].push_back(bal);
        cost[1].push_back(bal);
        edge[0].push_back(1);
        edge[1].push_back(0);

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
                for(int i=0; i<n; i++)
                {
                    double bal = sqrt((a[n]-a[i])*(a[n]-a[i])+(b[n]-b[i])*(b[n]-b[i])) * .006;
                    cost[i].push_back(bal);
                    cost[n].push_back(bal);
                    edge[n].push_back(i);
                    edge[i].push_back(n);
                }
                n++;
                kount++;
            }
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
