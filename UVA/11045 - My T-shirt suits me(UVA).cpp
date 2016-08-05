#include <cstdio>
#include <iostream>
#include <queue>
#include <map>
#include <cstring>
using namespace std;

map <string, int> mm;

int par[60], visit[60], edge[60][60], node;

int bfs(void)
{
    memset(visit, 0, sizeof(visit));

    queue <int> q;

    par[1] = -1;
    q.push(1);
    visit[1] = 1;

    int i, u;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(i = 1; i <= node; ++i)
        {
            if(visit[i] == 0 && edge[u][i] > 0)
            {
                par[i] = u;
                if(i == node)
                    return 1;
                visit[i] = 1;
                q.push(i);
            }
        }
    }
    return 0;
}

int main()
{
    int t, cnt, n, m, x, i, ans;
    char a[5], b[5];
    mm["XXL"] = 2, mm["XL"] = 3, mm["XS"] = 4, mm["L"] = 5, mm["S"] = 6, mm["M"] = 7;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        memset(edge, 0, sizeof(edge));
        scanf("%d %d", &n, &m);
        n /= 6;
        node = m + 8;
        ans = 0;
        for(i = 0; i < m; ++i)
        {
            scanf("%s %s", a, b);
            edge[1][mm[a]] = n;
//            edge[mm[a]][1] = n;
            edge[1][mm[b]] = n;
//            edge[mm[b]][1] = n;
            x = i + 8;
            edge[mm[a]][x] = 1;
            edge[mm[b]][x] = 1;
            edge[x][mm[a]] = 1;
            edge[x][mm[b]] = 1;
            edge[x][node] = 1;
        }

        while(bfs())
        {
            x = node;
            while(par[x] > 0)
            {
                edge[par[x]][x] -= 1;
                edge[x][par[x]] += 1;
                x = par[x];
            }

            ++ans;
        }

        if(ans == m)
            printf("YES\n", cnt);
        else
            printf("NO\n", cnt);
    }
    return 0;
}

