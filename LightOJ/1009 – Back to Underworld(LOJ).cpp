#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector <int> edge[20005];

int visit[20005], p, q;

void dfs(int s, int define)
{
    if(define == 1)
        ++p, define = 0;
    else
        ++q, define = 1;
    visit[s] = 1;

    int x = edge[s].size(), i;
    for(i = 0; i < x; ++i)
    {
        if(!visit[edge[s][i]])
        {
            dfs(edge[s][i], define);
        }
    }
}

int main()
{
    int t, cnt, n, a, b, i, ans;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
        {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        ans = 0;
        for(i = 1; i <= 20000; ++i)
        {
            if(!visit[i] && edge[i].size() > 0)
            {
                p = q = 0;
                dfs(i, 1);
                ans += max(p, q);
            }
        }
        printf("Case %d: %d\n", cnt, ans);

        for(i = 1; i <= 20000; ++i)
            edge[i].clear(), visit[i] = 0;
    }
    return 0;
}
