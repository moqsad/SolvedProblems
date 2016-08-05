#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int taken[100010];
vector <int> conn[100010];
stack <int> S;
int z;

void dfs(int p)
{
    int i, x;

    if(taken[p] == 0)
    {
        taken[p] = 1;
        x = conn[p].size();
        for(i = 0; i < x; ++i)
            dfs(conn[p][i]);
        S.push(p);
//        taken[p] = 1;
    }
    return;
}

void dfs2(int p)
{
    int i, x;
    if(taken[p] == 0)
    {
        taken[p] = 1;
        x = conn[p].size();
        for(i = 0; i < x; ++i)
            dfs2(conn[p][i]);
    }
    return;
}

int main()
{
    int t, cnt, i, j, n, m, ans, a, b;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        ans = 0;
        memset(taken, 0, sizeof(taken));
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            conn[a].push_back(b);
        }

        for(i = 1; i <= n; ++i)
        {
            if(!taken[i])
            {
                dfs(i);
            }
        }

        memset(taken, 0, sizeof(taken));

        while(!S.empty())
        {
            if(!taken[S.top()])
            {
                dfs2(S.top());
                ++ans;
            }
            S.pop();
        }

        while(!S.empty())
            S.pop();

        printf("%d\n", ans);
        for(i = 1; i <= n; ++i)
            conn[i].clear();
    }
    return 0;
}

