#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector <int> g1[1010];
vector <int> g2[1010];

stack <int> S;

bool taken[1010];
char arr[50];

void dfs1(int p)
{
    int i, x;
    if(!taken[p])
    {
        taken[p] = 1;
        x = g1[p].size();
        for(i = 0; i < x; ++i)
            dfs1(g1[p][i]);
        S.push(p);
    }
}

void dfs2(int p)
{
    int i, x;
    if(!taken[p])
    {
        taken[p] = 1;
        x = g2[p].size();
        for(i = 0; i < x; ++i)
            dfs2(g2[p][i]);
    }
}

int main()
{
    int n, m, i, j, x, y, ans;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
            break;
        ans = 0;
        getchar();
        mm.clear();
        for(i = 1; i <= n; ++i)
        {
            gets(arr);
            mm[arr] = i;
        }
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &x, &y);
            g1[x].push_back(y);
            g2[y].push_back(x);
        }
        for(i = 1; i <= n; ++i)
            dfs1(i);
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
        memset(taken, 0, sizeof(taken));
        printf("%d\n", ans);
        for(i = 1; i <= n; ++i)
        {
            g1[i].clear();
            g2[i].clear();
        }
    }
    return 0;
}
