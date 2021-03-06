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
using namespace std;//ACCEPTED..............

double d[210];
vector <double> cost[210];
vector <long long int> edge[210];
long long int k, finish;
string arr;
char letter[10000000];

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
    for(i = 0; i < k; ++i)
        d[i] = 100000000000.0;

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
    long long int cnt, i, j, x, n, m, t, a[2100], b[2100];
    double y, z, p;
    scanf("%lld\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld %lld %lld", &a[0], &b[0], &a[1], &b[1]);
        getchar();

        k = 2;

        while(getline(cin, arr))
        {
            if(arr[0] == '\0')
                break;
            i = 0;
            x = arr.size();

            j = 0;
            while(isdigit(arr[i]) || arr[i] == '-')
            {
                letter[j++] = arr[i];
                ++i;
            }
            letter[j] = '\0';
            a[k] = atol(letter);
            while(arr[i] == ' ')
                ++i;

            j = 0;
            while(isdigit(arr[i]) || arr[i] == '-')
            {
                letter[j++] = arr[i];
                ++i;
            }
            letter[j] = '\0';
            b[k] = atol(letter);
            while(arr[i] == ' ')
                ++i;
            ++k;

            while(i < x)
            {
                j = 0;
                while(isdigit(arr[i]) || arr[i] == '-')
                {
                    letter[j++] = arr[i];
                    ++i;
                }
                letter[j] = '\0';
                a[k] = atol(letter);
                while(arr[i] == ' ')
                    ++i;

                j = 0;
                while(isdigit(arr[i]) || arr[i] == '-')
                {
                    letter[j++] = arr[i];
                    ++i;
                }
                letter[j] = '\0';
                b[k] = atol(letter);
                if(a[k] == -1 && b[k] == -1)
                    break;
                y = a[k] - a[k-1];
                z = b[k] - b[k-1];
                p = sqrt(y * y + z * z) * .0015;
                edge[k].push_back(k-1);
                edge[k-1].push_back(k);
                cost[k].push_back(p);
                cost[k-1].push_back(p);

                while(arr[i] == ' ')
                    ++i;
                ++k;
            }
        }

        for(i = 0; i < k; ++i)
            for(j = i + 1; j  < k; ++j)
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
        for(i = 0; i < k; ++i)
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
0 0 0   5000 -1 -1
0 5000   0 10000 -1 -1
*/

