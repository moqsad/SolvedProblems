#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int start, dist[1100];
bool visit[1100];
vector <int> v[1100];
queue <int> Q;

void BFS(void)
{
    memset(dist, -1, sizeof(dist));
    memset(visit, 0, sizeof(visit));
    while(!Q.empty())
        Q.pop();

    visit[start] = 1;
    dist[start] = 0;
    Q.push(start);

    int u, i, x;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = v[u].size();
        for(i = 0; i < x; ++i)
        {
            if(visit[v[u][i]] == 0)
            {
                dist[v[u][i]] = dist[u] + 1;
                visit[v[u][i]] = 1;
                Q.push(v[u][i]);
            }
        }
    }
    return ;
}

int main()
{
    int t, cnt, i, a, b, p, d;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &p, &d);
        for(i = 0; i < d; ++i)
        {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        start = 0;
        BFS();
        for(i = 1; i < p; ++i)
        {
            printf("%d\n", dist[i]);
        }
        for(i = 0; i < p; ++i)
            v[i].clear();
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
