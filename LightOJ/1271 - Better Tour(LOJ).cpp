#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

int arr[50005], par[50005], visit[50005], e;

vector <int> edge[50005];

void bfs(int s)
{
    queue <int> q;

    q.push(s);
    visit[s] = 1;

    int i, u, x, y;

    while(!q.empty())
    {
        u = q.front();

        q.pop();

        x = edge[u].size();

        for(i = 0; i < x; ++i)
        {
            y = edge[u][i];

            if(!visit[y])
            {
                q.push(y);
                visit[y] = visit[u] + 1;
                par[y] = u;
            }

            else if(u < par[y] && visit[y] > visit[u])
                par[y] = u;
        }
    }
}

void print(int s)
{
    if(s == e)
    {
        printf("%d", e);
        return ;
    }
    printf("%d ", s);
    print(par[s]);
}

int main()
{
    int t, cnt, i, n;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &arr[0]);

        for(i = 1; i < n; ++i)
        {
            scanf("%d", &arr[i]);
            edge[arr[i - 1]].push_back(arr[i]);
            edge[arr[i]].push_back(arr[i - 1]);
        }

        bfs(arr[n - 1]);

        printf("Case %d:\n", cnt);
        e = arr[n - 1];
        print(arr[0]);
        printf("\n");

        for(i = 0; i < n; ++i)
        {
            edge[arr[i]].clear();
            visit[arr[i]] = 0;
        }
    }
    return 0;
}
