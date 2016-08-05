#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

#define inf 100000000000

struct data
{
    int u, v, c;
};

data arr[1010];

long long dist[1010];

bool ans[1010], visit[1010], color[1005][1005];
int source;

vector <int> edge[1010];

bool dfs(int start)
{
    if(ans[start])
        return 1;

    visit[start] = 1;

    int i, x;

    x = edge[start].size();

    for(i = 0; i < x; ++i)
    {
        if(!visit[edge[start][i]])
        {
            if(dfs(edge[start][i]))
                return 1;
        }
    }

    return 0;
}

void dfs2(int start)
{
    color[source][start] = 1;

    int i, x;

    x = edge[start].size();

    for(i = 0; i < x; ++i)
        if(!color[source][edge[start][i]])
            dfs2(edge[start][i]);
}

int main()
{
    int n, m, i, j, t, cnt, ace;

    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &arr[i].u, &arr[i].v, &arr[i].c);
            edge[arr[i].u].push_back(arr[i].v);
        }

//        memset(color, 0, sizeof(color));

        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                color[i][j] = 0;

        for(source = 0; source < n; ++source)
            dfs2(source);

        for(i = 1; i < n; ++i)
        {
            for(j = 0; j < m; ++j)
            {
                if(dist[arr[j].v] > dist[arr[j].u] + arr[j].c && color[arr[j].v][arr[j].u] == 1)
                    dist[arr[j].v] = dist[arr[j].u] + arr[j].c;
            }
        }

        ace = 0;
        for(j = 0; j < m; ++j)
        {
            if(dist[arr[j].v] > dist[arr[j].u] + arr[j].c && color[arr[j].v][arr[j].u] == 1)
            {
                dist[arr[j].v] = dist[arr[j].u] + arr[j].c;
                ans[arr[j].v] = 1;
                ace = 1;
            }
        }

        if(ace)
        {
            printf("Case %d:", cnt);

            for(j = 0; j < n; ++j)
            {
                memset(visit, 0, sizeof(visit));
                if(dfs(j))
                    printf(" %d",  j);
            }
            printf("\n");
        }

        else
            printf("Case %d: impossible\n", cnt);

        for(i = 0; i < n; ++i)
        {
            edge[i].clear();
            ans[i] = dist[i] = 0;
        }
    }
    return 0;
}
