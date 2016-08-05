#include <cstdio>
#include <utility>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, par[100001][18], visit[100001], min_cost[100001][18], max_cost[100001][18], length[100001], j, min_, max_;

vector <int> edge[100001];
vector <int> cost[100001];

void dfs(int s, int dist)
{
    visit[s] = 1;

    int x = edge[s].size(), y, i;
    ++dist;
    for(i = 0; i < x; ++i)
    {
        y = edge[s][i];
        if(!visit[y])
        {
            min_cost[y][0] = max_cost[y][0] = cost[s][i];
            length[y] = dist;
            par[y][0] = s;
            dfs(y, dist);
        }
    }
}

void lca_init(void)
{
    int i;

    for(j = 1; (1 << j) < n; ++j)
        for(i = 2; i <= n; ++i)
            if(par[i][j - 1] != -1 && par[par[i][j-1]][j - 1] != -1)
            {
                min_cost[i][j] = min(min_cost[i][j - 1], min_cost[par[i][j-1]][j - 1]);
                max_cost[i][j] = max(max_cost[i][j - 1], max_cost[par[i][j-1]][j - 1]);
                par[i][j] = par[par[i][j-1]][j - 1];
            }
}

void lca_find(int a, int b)
{
    if(length[a] < length[b])
        swap(a, b);

    int i;
    for(i = j - 1; i >= 0; i--)
        if(length[a] - (1 << i) >= length[b])
        {
            min_ = min(min_, min_cost[a][i]);
            max_ = max(max_, max_cost[a][i]);
            a = par[a][i];
        }

    if(a == b)
        return ;

    for(i = j - 1; i >= 0; i--)
    {
        if(par[a][i] != -1 && par[a][i] != par[b][i])
        {
            min_ = min(min(min_, min_cost[a][i]), min_cost[b][i]);
            max_ = max(max(max_, max_cost[a][i]), max_cost[b][i]);
            a = par[a][i];
            b = par[b][i];
        }
    }

    min_ = min(min(min_, min_cost[a][0]), min_cost[b][0]);
    max_ = max(max(max_, max_cost[a][0]), max_cost[b][0]);
}

int main()
{
    int t, cnt, i, k, a, b, c, q;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        for(i = 1; i < n; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a].push_back(b);
            edge[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }

        memset(par, -1, sizeof(par));

        dfs(1, 0);

        j = 0;
        lca_init();

        printf("Case %d:\n", cnt);
        scanf("%d", &q);
        for(i = 0; i < q; ++i)
        {
            scanf("%d %d", &a, &b);
            min_ = 1000000000;
            max_ = 0;
            lca_find(a, b);
            printf("%d %d\n", min_, max_);
        }

        for(i = 1; i <= n; ++i)
        {
            edge[i].clear();
            cost[i].clear();
            visit[i] = 0;
        }
    }
    return 0;
}
