#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define sz 1005

vector <int> edge[sz];
int visit[sz], match[sz], in[sz];

int dfs(int s)
{
    int i, y, x = edge[s].size();

    for(i = 0; i < x; ++i)
    {
        y = edge[s][i];

        if(!visit[y])
        {
            visit[y] = 1;
            if(!match[y] || dfs(match[y]))
            {
                match[y] = s;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int t, cnt, i, m, n, a, b, ans, j, x, y;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
        }

        ans = 0;
        for(i = 1; i <= n; ++i)
        {
            memset(visit, 0, sizeof(visit));
            x = edge[i].size();
            for(j = 0; j < x; ++j)
            {
                y = edge[i][j];
                if(match[y] == 0)
                {
                    match[y] = i;
                    break;
                }
            }
            if(j == x && !dfs(i))
                ++ans;
        }

        printf("Case %d: %d\n", cnt, ans);

        for(i = 1; i <= n; ++i)
        {
            edge[i].clear();
            match[i] = 0;
        }
    }
    return 0;
}
