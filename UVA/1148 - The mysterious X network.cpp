#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

vector <int> edge[100010];
int visit[100010], d[100010];

int BFS(int start, int end_)
{
    memset(visit, 0, sizeof(visit));
    d[start] = 0;
    visit[start] = 1;
    queue <int> q;
    q.push(start);
    int u, i, x, y;
    while(!q.empty())
    {
        u= q.front();
        q.pop();
        x = edge[u].size();
        for(i = 0; i <  x; ++i)
        {
            y = edge[u][i];
            if(visit[y] == 0)
            {
                d[y] = d[u] + 1;
                if(y == end_)
                    break;
                visit[y] = 1;
                q.push(y);
            }
        }
        if(y == end_)
            break;
    }
    return d[end_];
}

int main()
{
    int t, cnt, a, b, c, i, j, n, start, end_;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%d %d", &a, &b);
            for(j = 0; j <  b; ++j)
            {
                scanf("%d", &c);
                edge[a].push_back(c);
            }
        }

        scanf("%d %d", &start, &end_);
        printf("%d %d %d\n", start, end_, BFS(start, end_) - 1);
        if(cnt < t)
            printf("\n");

            for(i = 0; i < n; ++i)
                edge[i].clear();
    }
    return 0;
}
