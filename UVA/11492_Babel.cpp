#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

vector <int> cost[4010];
vector <string> ss[4010];
vector <int> vv[4010];
int d[4010][125], j;
char a[60], b[60], c[60], start[60], finish[60];
string x;
map <string, int> mm;

struct data
{
    int city, dist, alpha;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

void dijkstra(int start)
{
    int i, k, x, y, p = 0;
    for(i = 0; i <= j; ++i)
        for(k = 97; k < 123; ++k)
            d[i][k] = 1000010;
    priority_queue <data> Q;
    data u, v;
    d[start][0] = 0;
    u.city = start;
    u.dist = 0;
    u.alpha = 0;
    Q.push(u);
    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();
//        printf("%d|||||||||||||\n", u.city);
        x = vv[u.city].size();
        for(i = 0; i < x; ++i)
        {
            y = ss[u.city][i][0];
            if(u.alpha != y)
            {
//                printf("+++++++++++\n");
                v.alpha = y;
                v.city = vv[u.city][i];
                v.dist = cost[u.city][i] + d[u.city][u.alpha];
//                printf("%d %d %d__\n", v.city, v.dist, d[v.city][v.alpha]);
                if(d[v.city][v.alpha] > v.dist)
                {
                    d[v.city][v.alpha] = v.dist;
//                    printf("%d_____________\n", v.dist);
                    Q.push(v);
                }
            }
        }
    }
}

int main()
{
    int i, k, m, total, p;
    while(scanf("%d", &m) == 1)
    {
        if(m == 0)
            break;
        j = -1;
        scanf("%s %s", start, finish);
        for(i = 0; i < m; ++i)
        {
            scanf("%s %s %s", a, b, c);
            if(mm.find(a) == mm.end())
            {
                x = a;
                mm[a] = ++j;
            }
            if(mm.find(b) == mm.end())
            {
                x = b;
                mm[b] = ++j;
            }
            vv[mm[a]].push_back(mm[b]);
            vv[mm[b]].push_back(mm[a]);

            ss[mm[a]].push_back(c);
            ss[mm[b]].push_back(c);

            cost[mm[a]].push_back(strlen(c));
            cost[mm[b]].push_back(strlen(c));
        }
        if(mm.find(start) != mm.end() && mm.find(finish) != mm.end())
        {
            if(strcmp(start, finish) == 0)
                printf("0\n");
            else
            {
                dijkstra(mm[start]);
                p = 0;
                total = 1000010;
                for(i = 97; i < 123; ++i)
                    if(d[mm[finish]][i] < total)
                    {
                        p = 1;
                        total = d[mm[finish]][i];
                    }
                if(p == 1)
                    printf("%d\n", total);
                else
                    printf("impossivel\n");
            }
        }
        else
            printf("impossivel\n");
        for(i = 0; i <= j; ++i)
        {
            vv[i].clear();
            cost[i].clear();
            ss[i].clear();
        }
        mm.clear();
    }
    return 0;
}
