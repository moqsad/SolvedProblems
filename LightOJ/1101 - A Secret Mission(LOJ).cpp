#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct data
{
    int u, v, w;
};

vector <data> v1;
data info;
int j, n, min_, p[50002][17], length[50002], visit[50002], min_cost[50002][17], par[50002];
vector <int> edge[50002], cost[50002];

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

void dfs(int node, int dist)
{
    visit[node] = 1;

    int i, y, x = edge[node].size();
    ++dist;

    for(i = 0; i < x; ++i)
    {
        y = edge[node][i];
        if(visit[y] == 0)
        {
            p[y][0] = node;
            min_cost[y][0] = cost[node][i];
            length[y] = dist;
            dfs(y, dist);
        }
    }
}

void lca_init(void)
{
    int i;
    for(j = 1; (1 << j) < n; ++j)
        for(i = 2; i <= n; ++i)
        {
            if(p[i][j - 1] != -1 && p[p[i][j - 1]][j - 1] != -1)
            {
                min_cost[i][j] = max(min_cost[i][j - 1], min_cost[p[i][j - 1]][j - 1]);
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
}

void lca_find(int a, int b)
{
    if(length[a] < length[b])
        swap(a, b);

    int i;
    for(i = j - 1; i >= 0; --i)
    {
        if(length[a] - (1 << i) >= length[b])
        {
            min_ = max(min_, min_cost[a][i]);
            a = p[a][i];
        }
    }


    if(a == b)
        return ;

    for(i = j - 1; i >= 0; i--)
    {
        if(p[a][i] != -1 && p[a][i] != p[b][i])
        {
            min_ = max(max(min_, min_cost[a][i]), min_cost[b][i]);
            a = p[a][i];
            b = p[b][i];
        }
    }

    min_ = max(max(min_, min_cost[a][0]), min_cost[b][0]);
}

int main()
{
    int t, cnt, m, i, c, x, y, q;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);

        for(i = 1; i <= n; ++i)
            par[i] = i;

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &info.u, &info.v, &info.w);
            v1.push_back(info);
        }

        sort(v1.begin(), v1.end(), comp);

        c = 0;
        for(i = 0; i < m; ++i)
        {
            x = func(v1[i].u);
            y = func(v1[i].v);
            if(x != y)
            {
                par[x] = y;
                ++c;
                edge[v1[i].u].push_back(v1[i].v);
                edge[v1[i].v].push_back(v1[i].u);
                cost[v1[i].u].push_back(v1[i].w);
                cost[v1[i].v].push_back(v1[i].w);
                if(c == n - 1)
                    break;
            }
        }

        memset(p, -1, sizeof(p));

        dfs(1, 0);

        lca_init();

        printf("Case %d:\n", cnt);
        scanf("%d", &q);
        for(i = 0; i < q; ++i)
        {
            scanf("%d %d", &x, &y);

            min_ = 0;

            lca_find(x, y);

            printf("%d\n", min_);
        }

        for(i = 1; i <= n; ++i)
        {
            visit[i] = 0;
            edge[i].clear();
            cost[i].clear();
        }
        v1.clear();
    }
    return 0;
}
