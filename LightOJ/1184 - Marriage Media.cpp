#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;

vector <int> edge[55];

struct data
{
    int h, a, d;
};

data man[55];

int match[105], visit[105];

int dfs(int node)
{
    int x = edge[node].size(), i, v;
    for(i = 0; i < x; ++i)
    {
        v = edge[node][i];

        if(visit[v])
            continue ;

        visit[v] = 1;

        if(match[v] == 0 || dfs(match[v]))
        {
            match[v] = node;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t, cnt, i, j, m, w, x, y, z, ans, s;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &m, &w);

        ++m;

        for(i = 1; i < m; ++i)
            scanf("%d %d %d", &man[i].h, &man[i].a, &man[i].d);

        for(i = 1; i <= w; ++i)
        {
            scanf("%d %d %d", &x, &y, &z);
            for(j = 1; j < m; ++j)
            {
                if(abs(x - man[j].h) <= 12 && abs(y - man[j].a) <= 5 && z == man[j].d)
                    edge[j].push_back(i + m);
            }
        }

        ans = 0;
        s = m + w + 5;
        for(i = 1; i < m; ++i)
        {
            memset(visit, 0, sizeof(int) * (s));
            if(dfs(i))
                ++ans;
        }

        printf("Case %d: %d\n", cnt, ans);

        for(i = 1; i < m; ++i)
            edge[i].clear();

        memset(match, 0, sizeof(int) * s);
    }
    return 0;
}

/*
1 1
2 2 2
2 2 2
*/
