#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

vector <int> edge[3][50];
vector <int> cost[3][50];
int d[3][50];

map <char, int> mm;
map <int, char> nn;

struct data
{
    int dist, city;
    bool operator < (const data & p) const
    {
        return dist > p.dist;
    }
};

priority_queue <data> Q;

void dijkstra(int a, int start)
{
    int i, x, y;
    data u, v;

    d[a][start] = 0;
    u.city = start;
    u.dist = 0;
    Q.push(u);
    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();
        x = edge[a][u.city].size();
        for(i = 0; i < x; ++i)
        {
            y = edge[a][u.city][i];
            v.city = y;
            v.dist = d[a][u.city] + cost[a][u.city][i];
            if(d[a][y] > v.dist)
            {
                d[a][y] = v.dist;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int n, i, weight, j, k, p, x, total;
    char whose, direction, ch1, ch2, arr[50];
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        j = 0;
        for(i = 0; i < n; ++i)
        {
            scanf(" %c %c %c %c %d", &whose, &direction, &ch1, &ch2, &weight);
            if(mm.find(ch1) == mm.end())
            {
                mm[ch1] = ++j;
                nn[j] = ch1;
            }
            if(mm.find(ch2) == mm.end())
            {
                mm[ch2] = ++j;
                nn[j] = ch2;
            }
            p = 1;
            if(whose == 'Y')
                p = 0;
            if(direction == 'U')
            {
                edge[p][mm[ch1]].push_back(mm[ch2]);
                cost[p][mm[ch1]].push_back(weight);
            }
            else
            {
                edge[p][mm[ch1]].push_back(mm[ch2]);
                cost[p][mm[ch1]].push_back(weight);
                edge[p][mm[ch2]].push_back(mm[ch1]);
                cost[p][mm[ch2]].push_back(weight);
            }
        }

        scanf(" %c %c", &ch1, &ch2);
        for(i = 0; i < 2; ++i)
            for(k = 1; k <= j; ++k)
                d[i][k] = 999999999;

        dijkstra(0, mm[ch1]);
        dijkstra(1, mm[ch2]);
        total = 999999999;
        for(i = 1; i <= j; ++i)
        {
            x = d[0][i] + d[1][i];
            if(x < total)
                total =  x;
        }

        if(total < 999999999)
        {
            k = 0;
            for(i = 1; i <= j; ++i)
            {
                x = d[0][i] + d[1][i];
                if(x == total)
                    arr[k++] = nn[i];
            }
            sort(arr, arr + k);
            printf("%d", total);
            for(i = 0; i < k; ++i)
                printf(" %c", arr[i]);
                printf("\n");
        }
        else
            printf("You will never meet.\n");
        for(i = 0; i < 2; ++i)
            for(k = 1; k <= j; ++k)
            {
                edge[i][k].clear();
                cost[i][k].clear();
            }
        mm.clear();
        nn.clear();
    }
    return 0;
}
