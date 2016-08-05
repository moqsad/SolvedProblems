#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector <int> v[110];
queue <int> Q;

int start, value[110], dist[110];
bool visit[110];

void bfs(void)
{
    memset(visit, 0, sizeof(visit));
    memset(dist, 0, sizeof(dist));
    visit[start] = 1;
    Q.push(start);

    int i, x, y, u;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = v[u].size();
        for(i = 0; i < x; ++i)
        {
            y = v[u][i];
            if(!visit[y])
            {
                visit[y] = 1;
                dist[y] = dist[u] + 1;
                value[y] += dist[y];
                Q.push(y);
            }
        }
    }
}

int main()
{
    int cnt, t, i, m, n, a, b, total;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        memset(value, 0, sizeof(value));
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        scanf("%d %d", &a, &b);
        start = a;
        bfs();
        start = b;
        bfs();
        total = 0;
        for(i = 0; i < n; ++i)
        {
            if(value[i] > total)
                total = value[i];
            v[i].clear();
        }
        printf("Case %d: %d\n", cnt, total);
    }
    return 0;
}
