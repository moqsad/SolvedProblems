#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;

vector <int> g[50005], gr[50005], store, dag[50005];

int p, visit[50005], min_[50005], total[50005], scc[50005], t2, m, dp[50005];

void dfs(int st)
{
    int i, x;
    visit[st] = 1;
    x = g[st].size();
    for(i = 0; i < x; ++i)
    {
        if(!visit[g[st][i]])
            dfs(g[st][i]);
    }
    store.push_back(st);
}

void dfs2(int st)
{
    int i, x;
    scc[st] = p;
    ++t2;
    m = min(m, st);
    visit[st] = 1;
    x = gr[st].size();
    for(i = 0; i < x; ++i)
    {
        if(!visit[gr[st][i]])
            dfs2(gr[st][i]);
    }
}

int func(int st)
{
    if(dp[st] != -1)
        return dp[st];

    int i, x, sum = total[st];
    x = dag[st].size();

    for(i = 0; i < x; ++i)
        sum += func(dag[st][i]);

    return dp[st] = sum;
}

int main()
{
    int t, cnt, n, i, j, a, b, max_, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 1; i <=  n;  ++i)
        {
            scanf("%d %d", &a, &b);
            g[a].push_back(b);
            gr[b].push_back(a);
        }

        for(i = 1; i <= n; ++i)
            if(!visit[i])
                dfs(i);

        p = 0;
        memset(visit, 0, sizeof(visit));
        for(i = n - 1; i >= 0; --i)
        {
            if(!visit[store[i]])
            {
                t2 = 0;
                ++p;
                m = store[i];
                dfs2(store[i]);
                total[p] = t2;
                min_[p] = m;
            }
        }

        for(i = 1; i <= n; ++i)
        {
            a = scc[i];
            x = g[i].size();
            for(j = 0; j < x; ++j)
            {
                b = scc[g[i][j]];
                if(a != b)
                    dag[a].push_back(b);
            }
        }

        memset(dp, -1, sizeof(dp));
        m = min_[1];
        max_ = 0;
        for(i = 1; i <= p; ++i)
        {
            t2 = func(i);
            if(max_ < t2)
            {
                max_  = t2;
                m = min_[i];
            }

            else if(max_ == t2 && m > min_[i])
                m = min_[i];
        }
        printf("Case %d: %d\n", cnt, m);
        for(i = 1; i <= n; ++i)
        {
            dag[i].clear();
            g[i].clear();
            gr[i].clear();
            visit[i]  = 0;
        }
        store.clear();
    }
    return 0;
}

/*
3
3
1 2
2 3
3 1
4
1 2
2 1
4 3
3 2
5
1 2
2 1
5 3
3 4
4 5
*/
