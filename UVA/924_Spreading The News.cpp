#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

bool visit[3000];
int start, dist[3000], highest[3000], y;
vector <int> v[3000];
queue <int> Q;

void BFS(void)
{
    memset(visit, 0, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    memset(highest, 0, sizeof(highest));
    while(!Q.empty())
        Q.pop();

    Q.push(start);
    visit[start] = 1;
    dist[start] = 0;
    int i, u, x;
    y = 0;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();

        x = v[u].size();
        for(i = 0; i < x; ++i)
        {
            if(visit[v[u][i]] == 0)
            {
                y = dist[v[u][i]] = dist[u] + 1;
                ++highest[y];
                visit[v[u][i]] = 1;
                Q.push(v[u][i]);
            }
        }
    }
    return ;
}

int main()
{
    int e, n, i, cnt, a, q, sum, d;
    while(scanf("%d", &e) == 1)
    {
        for(cnt = 0; cnt < e; ++cnt)
        {
            scanf("%d", &n);
            for(i = 0; i < n; ++i)
            {
                scanf("%d", &a);
                v[cnt].push_back(a);
            }
        }
        scanf("%d", &q);
        for(cnt = 0; cnt < q; ++cnt)
        {
            scanf("%d", &start);
            BFS();
            sum = 0;
            if(y > 0)
            {
                for(i = 1; i <= y; ++i)
                {
                    if(highest[i] > sum)
                    {
                        sum = highest[i];
                        d = i;
                    }
                }
                printf("%d %d\n", sum, d);
            }
            else
                printf("0\n");
        }
        for(cnt = 0; cnt < e; ++cnt)
            v[cnt].clear();
    }
    return 0;
}
