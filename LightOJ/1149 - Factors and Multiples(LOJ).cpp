#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[105], match[105];
bool visit[105];

vector <int> edge[105];

bool dfs(int node)
{
    int x = edge[node].size(), v, i;

    for(i = 0; i < x; ++i)
    {
        v = edge[node][i];
        if(visit[v] == 1)
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
    int t, cnt, i, j, n, m, a, ans;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        for(i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);

        scanf("%d", &m);
        for(i = 1; i <= m; ++i)
        {
            scanf("%d", &a);
            for(j = 1; j <= n; ++j)
            {
                if(!(a % arr[j]))
                    edge[j].push_back(i);
            }
        }

        ans = 0;
        memset(match, 0, sizeof(match));
        for(i = 1; i <= n; ++i)
        {
            memset(visit, 0, sizeof(visit));
            if(dfs(i))
                ++ans;
        }

        printf("Case %d: %d\n", cnt, ans);

        for(i = 1; i <= n; ++i)
            edge[i].clear();
    }
    return 0;
}
