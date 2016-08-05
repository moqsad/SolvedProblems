#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int ans;
bool taken[10010];
vector <int> v[10100];

void dfs(int p)
{
    int i, x;
    if(!taken[p])
    {
        taken[p] = 1;
        ++ans;
        x = v[p].size();
        for(i = 0; i < x; ++i)
            dfs(v[p][i]);
    }
}

int main()
{
    int t, n, m, l, i, j, cnt, x, y;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        memset(taken, 0, sizeof(taken));
        ans = 0;
        scanf("%d %d %d", &n, &m, &l);
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &x, &y);
            v[x].push_back(y);
        }

        for(i = 0; i < l; ++i)
        {
            scanf("%d", &x);
            dfs(x);
        }
        printf("%d\n", ans);
        for(i = 1; i <= n; ++i)
            v[i].clear();
    }
    return 0;
}
