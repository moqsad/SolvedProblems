#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

#define inf 10000000000000

long long n, m, end_, par[105], visit[105], edge[105][105];

long long bfs(void)
{
    long long i, u;
    memset(visit,0,sizeof(visit));

    queue <long long> q;
    q.push(1);
    visit[1] = 1;
    par[1] = -1;

    while(!q.empty())
    {
        u = q.front();
        q.pop();

        for(i = 1; i <= n; ++i)
        {
            if(edge[u][i] > 0 && visit[i] == 0)
            {
                par[i] = u;
                if(i == end_)
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
    long long t, cnt, i, a, b, c, ans, min_, x;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        memset(edge, 0, sizeof(edge));
        ans = 0;
        scanf("%lld %lld",&n, &m);

        for(i = 2; i < n; ++i)
        {
            scanf("%lld", &c);
            edge[i][i + n] = c;
            edge[i + n][i] = c;
        }

        edge[1][1 + n] = edge[n][n + n] = inf;
        for(i = 0; i < m; ++i)
        {
            scanf("%lld %lld %lld", &a, &b, &c);
            edge[a + n][b] = c;
            edge[b + n][a] = c;
        }

        end_ = n;
        n += n;
        while(bfs())
        {
            x = end_;
            min_ = inf;
            while(par[x] > 0)
            {
                min_ = min(edge[par[x]][x], min_);
                x = par[x];
            }

            x = end_;
            while(par[x] > 0)
            {
                edge[par[x]][x] -= min_;
                edge[x][par[x]] += min_;
                x = par[x];
            }
            ans += min_;
        }

        printf("Case %lld: %lld\n", cnt, ans);
    }
    return 0;
}
