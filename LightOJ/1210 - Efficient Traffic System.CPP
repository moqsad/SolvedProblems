#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector <int> g[20005], gr[20005], stk;

int scc[20005], p, in[20005], out[20005], visit[20005];

void dfs(int s)
{
    visit[s] = 1;
    int i, x = g[s].size();
    for(i = 0; i < x; ++i)
    {
        if(!visit[g[s][i]])
            dfs(g[s][i]);
    }
    stk.push_back(s);
}

void dfs2(int s)
{
    visit[s] = 1;
    int i, x = gr[s].size();
    for(i = 0; i < x; ++i)
    {
        if(!visit[gr[s][i]])
            dfs2(gr[s][i]);
    }
    scc[s] = p;
}

int main()
{
    int t, cnt, m, a, b, n, i, in_, out_, x, y, z, j;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
            gr[b].push_back(a);
        }

        for(i = 1; i <= n; ++i)
        {
            if(!visit[i])
                dfs(i);
        }

        p = 0;
        memset(visit, 0, sizeof(visit));
        for(i = n - 1; i >= 0; --i)
        {
            if(!visit[stk[i]])
            {
                ++p;
                dfs2(stk[i]);
            }
        }
//        printf("%d\n", p);

        in_ = out_ = 0;

        for(i = 1; i <= n; ++i)
        {
            x = scc[i];
            z = g[i].size();
            for(j = 0; j < z; ++j)
            {
                y = scc[g[i][j]];
                if(x != y)
                {
                    out[x] = 1;
                    in[y] = 1;
                }
            }
        }

        for(i = 1; i <= p; ++i)
        {
            if(in[i] == 0)
                ++in_;
            in[i] = 0;

            if(out[i] == 0)
                ++out_;
            out[i] = 0;

            visit[i] = 0;
            g[i].clear();
            gr[i].clear();
        }

        for(i = i; i <= n; ++i)
        {
            visit[i] = 0;
            g[i].clear();
            gr[i].clear();
        }
        stk.clear();

        if(p == 1)
            printf("Case %d: 0\n", cnt);
        else
            printf("Case %d: %d\n", cnt, max(in_, out_));
    }
    return 0;
}
