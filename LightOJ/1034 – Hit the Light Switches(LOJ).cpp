#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int visit[10010], store[10010], j;

vector <int> edge[10010];

void dfs(int start)
{
    int i, x;
    visit[start] = 1;
    x = edge[start].size();
    for(i = 0; i < x; ++i)
    {
        if(visit[edge[start][i]] == 0)
            dfs(edge[start][i]);
    }
    store[j++] = start;
}

void dfs2(int start)
{
    int i, x;
    visit[start] = 1;
    x = edge[start].size();
    for(i = 0; i < x; ++i)
    {
        if(visit[edge[start][i]] == 0)
            dfs2(edge[start][i]);
    }
}

int main()
{
    int cnt, t, n, m, i, ans, a, b;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
        }

        j = 1;
        for(i = 1; i <= n; ++i)
        {
            if(visit[i] == 0)
                dfs(i);
        }

        ans = 0;
        memset(visit, 0, sizeof(visit));
        for(i = n; i > 0; --i)
        {
            if(visit[store[i]] == 0)
            {
                dfs2(store[i]);
                ++ans;
            }
        }

        printf("Case %d: %d\n", cnt, ans);
        for(i = 1; i <= n; ++i)
        {
            visit[i] = 0;
            edge[i].clear();
        }
    }
    return 0;
}
