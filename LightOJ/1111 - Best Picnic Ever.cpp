#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

vector <int> edge[1005], u, v, w;

int visit[1005], arr[105];

void dfs(int s)
{
    visit[s] = 1;
//    u.push_back(s);

    int x = edge[s].size(), i;

    for(i = 0; i < x; ++i)
    {
        if(!visit[edge[s][i]])
            dfs(edge[s][i]);
    }
}

int main()
{
    int t, k, n, m, a, b, cnt, i, j, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d", &k, &n, &m);

        for(i = 0; i < k;  ++i)
            scanf("%d", &arr[i]);

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
        }

        memset(visit, 0, sizeof(visit));
        dfs(arr[0]);

        for(i = 1; i <= n; ++i)
            if(visit[i] == 1)
                u.push_back(i);

        for(i = 1; i < k; ++i)
        {
            v = u;
            memset(visit, 0, sizeof(visit));
            dfs(arr[i]);
            x = v.size();

            u.clear();
            for(j = 0; j < x; ++j)
            {
                if(visit[v[j]] == 1)
                    u.push_back(v[j]);
            }
        }
        printf("Case %d: %d\n", cnt, u.size());

        u.clear();
        for(i = 1; i <= n; ++i)
            edge[i].clear();
    }
    return 0;
}
