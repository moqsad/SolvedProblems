#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

bool visit[100010];
vector <int> v[100010];
vector <int> cost[100010];
vector <int> ans;

int dfs(int s, int done)
{
    visit[s] = 1;
    int i, x, y, z, p = 1;
    x = v[s].size();
    for(i = 0; i < x; ++i)
    {
        y = v[s][i];
        if(visit[y] == 0)
        {
            z = dfs(y, cost[s][i]);
            if(z == 0)
                p = 0;
        }
    }
    if(p == 1 && done == 2)
    {
        ans.push_back(s);
        return 0;
    }
    else
        return p;
}

int main()
{
    int n, a, b, c, i, j, x;
    while(scanf("%d", &n) == 1)
    {
        for(i = 1; i < n; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            v[a].push_back(b);
            v[b].push_back(a);

            cost[a].push_back(c);
            cost[b].push_back(c);
        }
        dfs(1, 1);
        x = ans.size();
        printf("%d\n", x);
        if(x > 0)
        {
            printf("%d", ans[0]);
            for(i = 1; i < x; ++i)
                printf(" %d", ans[i]);
            printf("\n");
        }
        for(i = 1; i <= n; ++i)
        {
            v[i].clear();
            cost[i].clear();
            visit[i] = 0;
        }
        ans.clear();
    }
    return 0;
}
