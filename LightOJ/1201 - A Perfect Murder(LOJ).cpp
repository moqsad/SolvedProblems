#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector <int> set1, edge[1005];

queue <int> q;

int visit[1005], match[1005];

void bfs(int source)
{
    q.push(source);
    visit[source] = 1;

    int i, u, x, y;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        x = edge[u].size();
        for(i = 0; i < x; ++i)
        {
            y = edge[u][i];
            if(visit[y] == 0)
            {
                q.push(y);
                if(visit[u] == 1)
                    visit[y] = 2;

                else
                    visit[y] = 1;
            }
        }
    }
}

int dfs(int node)
{
    int i, v, P = edge[node].size();
    for(i = 0; i < P; ++i)
    {
        v = edge[node][i];
        if(visit[v])
            continue ;
        visit[v] = 1;
        if(!match[v] || dfs(match[v]))
        {
            match[v] = node;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t, cnt, i, n, m, a, b, ans, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        ans = 0;

        for(i = 1; i <= n; ++i)
        {
            if(visit[i] == 0)
                bfs(i);
        }

        for(i = 1; i <= n; ++i)
        {
            if(visit[i] == 1)
                set1.push_back(i);
        }

        memset(match, 0, sizeof(int) * (n + 1));

        x = set1.size();
        for(i = 0; i < x; ++i)
        {
//            printf("%d_____________\n", set1[i]);
            memset(visit, 0, sizeof(int) * (n + 1));
            if(dfs(set1[i]))
                ++ans;
        }

        printf("Case %d: %d\n", cnt, n - ans);
        for(i = 1; i <= n; ++i)
        {
            edge[i].clear();
            visit[i] = 0;
        }
        set1.clear();
    }
    return 0;
}
