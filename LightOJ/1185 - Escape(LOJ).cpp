#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

vector <int> edge[105];

int ans, visit[105][3];

void dfs(int s)
{
    int i, y, x = edge[s].size();

    for(i = 0; i < x; ++i)
    {
        y = edge[s][i];

        if(visit[s][1] == 1 && visit[y][2] == 0)
        {
            ++ans;
            visit[y][2] = 1;
            dfs(y);
        }

        else if(visit[s][2] == 1 && visit[y][1] == 0)
        {
            visit[y][1] = 1;
            dfs(y);
        }
    }
}

int main()
{
    int t, cnt, i, n, m, a, b;
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

        if(edge[1].size() > 0)
        {
            ans = 1;
            visit[1][2] = 1;
            dfs(1);
            printf("Case %d: %d\n", cnt, ans);
        }
        else
            printf("Case %d: 0\n", cnt);

        for(i = 1; i <= n; ++i)
        {
            edge[i].clear();
            visit[i][1] = visit[i][2] = 0;
        }
    }
    return 0;
}
