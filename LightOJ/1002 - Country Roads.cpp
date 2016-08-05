#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

int par[550], cycle[550], d[550];

struct data
{
    int u, v, w;
};

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

bool comp(data p, data q)
{
    return p.w < q.w;
}

vector <data> v;

queue <int> q;

void union_(int x, int y)
{
    if(cycle[x] > cycle[y])
        par[y] = x;
    else
        par[x] = y;
    if(cycle[x] == cycle[y])
        ++cycle[y];
}

vector <int> edge[550];
vector <int> cost[550];

void bfs(int src)
{
    int i, x, y, u;
    memset(d, -1, sizeof(d));
    d[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        x = edge[u].size();
        for(i = 0; i < x; ++i)
        {
            y = edge[u][i];
            if(d[y] == -1)
            {
                if(d[u] > cost[u][i])
                    d[y] = d[u];
                else
                    d[y] = cost[u][i];
                q.push(y);
            }
        }
    }
}

int main()
{
    int n, m, i, j, t, cnt, src, x, y, z;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; ++i)
        {
            par[i] = i;
            cycle[i] = 0;
        }
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &info.u, &info.v, &info.w);
            v.push_back(info);
        }
        sort(v.begin(), v.end(), comp);
        j = 0;
        z = n - 1;
        for(i = 0; i < m; ++i)
        {
            x = func(v[i].u);
            y = func(v[i].v);
            if(x != y)
            {
                union_(x, y);
                ++j;
                cost[v[i].u].push_back(v[i].w);
                cost[v[i].v].push_back(v[i].w);
                edge[v[i].u].push_back(v[i].v);
                edge[v[i].v].push_back(v[i].u);
                if(j == z)
                    break;
            }
        }
        scanf("%d", &src);
        bfs(src);
        printf("Case %d:\n", cnt);
        for(i = 0; i < n; ++i)
        {
            if(d[i] != -1)
                printf("%d\n", d[i]);
            else
                printf("Impossible\n");
            edge[i].clear();
            cost[i].clear();
        }
        v.clear();
    }
    return 0;
}
