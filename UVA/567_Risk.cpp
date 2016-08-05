#include "bits/stdc++.h"
using namespace std;

queue <int> Q;
vector <int> v[25];
int start, finish, dist[25];
bool visit[25];

void BFS(void)
{
    memset(visit, 0, sizeof(visit));
    memset(dist, 0, sizeof(dist));

    while(!Q.empty())
        Q.pop();
    visit[start] = 1;
    Q.push(start);

    int u, i, x, p = 0;
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
                if(v[u][i] == finish)
                {
                    p = 1;
                    break;
                }
                Q.push(v[u][i]);
                visit[v[u][i]] = 1;
            }
        }
        if(p == 1)
            break;
    }
    return ;
}

int main()
{
    int n, a, cnt, i, q, serial = 0;
    while(scanf("%d", &n) == 1)
    {
        for(cnt = 1; cnt < 21; ++cnt)
        {
            while(!v[cnt].empty())
                v[cnt].pop_back();
        }
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            v[1].push_back(a);
            v[a].push_back(1);
        }
        for(cnt = 2; cnt < 20; ++cnt)
        {
            scanf("%d", &n);
            for(i = 0; i < n; ++i)
            {
                scanf("%d", &a);
                v[cnt].push_back(a);
                v[a].push_back(cnt);
            }
        }
        printf("Test Set #%d\n", ++serial);
        scanf("%d", &q);
        for(cnt = 0; cnt < q; ++cnt)
        {
            scanf("%d %d", &start, &finish);
            BFS();
            printf("%2d to %2d: %d\n", start, finish, dist[finish]);
        }
        printf("\n");
    }
    return 0;
}
