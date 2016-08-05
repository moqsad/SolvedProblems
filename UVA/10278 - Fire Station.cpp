#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

vector <int> edge[510];
vector <int> cost[510];

int f[110], in[510], din[510], inter, dist[510];
bool arr[110];
char letter[30];

struct data
{
    int city, d;
    bool operator < (const data & p) const
    {
        return d > p.d;
    }
};

void dijkstra(int source)
{
    data u, v;
    int i, x, y;
    for(i = 1; i <= inter; ++i)
        dist[i] = 2147483645;

    priority_queue <data> Q;
    u.city = source;
    u.d = 0;
    Q.push(u);
    dist[source] = 0;

    while(!Q.empty())
    {
        u = Q.top();
        Q.pop();

        x = edge[u.city].size();
        for(i = 0; i < x; ++i)
        {
            v.city = edge[u.city][i];
            v.d = dist[u.city] + cost[u.city][i];
            if(dist[v.city] > v.d)
            {
                dist[v.city] = v.d;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int i, j, k, l, x, y, z, cnt, t, ans, sum, total, a, fire;
    scanf("%d\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d\n", &fire, &inter);
        for(i = 1; i <= fire; ++i)
        {
            scanf("%d", &a);
            f[i] = a;
            arr[a] = 1;
        }
        getchar();
        j = i;

        k = 1;
        for(i=1; i <= inter; ++i)
            if(arr[i] == 0)
            {
                in[k++] = i;
                din[i] = 2147483645;
            }

        while(gets(letter))
        {
            if(letter[0] == '\0')
                break;
            sscanf(letter, "%d %d %d", &x, &y, &z);
            edge[x].push_back(y);
            edge[y].push_back(x);

            cost[x].push_back(z);
            cost[y].push_back(z);
        }

        for(i = 1; i < j; ++i)
        {
            dijkstra(f[i]);
            for(l= 1; l < k; ++l)
            {
                if(dist[in[l]] < din[in[l]])
                    din[in[l]] = dist[in[l]];
            }
        }

        ans =  1;
        sum = 2147483645;
        for(i = 1; i < k; ++i)
        {
            total = 0;
            dijkstra(in[i]);
            for(l= 1; l < k; ++l)
            {
                if(in[i] != in[l])
                {
                    x = dist[in[l]] < din[in[l]] ? dist[in[l]] : din[in[l]];
                    if(x > total)
                        total = x;
                }
            }
            if(total < sum)
            {
                sum = total;
                ans = in[i];
            }
        }
        printf("%d\n", ans);
        if(cnt <  t)
            printf("\n");
        for(i = 1; i <= inter; ++i)
        {
            edge[i].clear();
            cost[i].clear();
            arr[i] = 0;
        }
    }
    return 0;
}
