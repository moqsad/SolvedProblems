#include <cstring>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

vector <int> g1[2010];
vector <int> g2[2010];

bool taken[2010];

void dfs1(int p)
{
    int i, x;
    if(!taken[p])
    {
        taken[p] = 1;
        x = g1[p].size();
        for(i = 0; i < x; i++)
            dfs1(g1[p][i]);
    }
}

void dfs2(int p)
{
    int i, x;
    if(!taken[p])
    {
        taken[p] = 1;
        x = g2[p].size();
        for(i = 0; i < x; i++)
            dfs2(g2[p][i]);
    }
}

int main()
{
    int n, m, i, j, a, b, det, p;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(m == 0 && n == 0)
            break;
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &det);
            if(det == 2)
            {
                g1[a].push_back(b);
                g2[a].push_back(b);
                g1[b].push_back(a);
                g2[b].push_back(a);
            }
            else
            {
                g1[a].push_back(b);
                g2[b].push_back(a);
            }
        }
        p = 0;
        memset(taken, 0, sizeof(taken));
        dfs1(1);
        for(i = 1; i <= n; ++i)
            if(taken[i] == 0)
                break;
        if(i > n)
        {
            memset(taken, 0, sizeof(taken));
            dfs2(1);
            for(i = 1; i <= n; ++i)
                if(taken[i] == 0)
                    break;
            if(i > n)
                p = 1;
        }
        printf("%d\n", p);
        for(i = 1; i <= n; ++i)
        {
            g1[i].clear();
            g2[i].clear();
        }
    }
    return 0;
}
