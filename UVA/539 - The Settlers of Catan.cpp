#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector <int> edge[30];

int total;

void backtrack(int conn[][30], int node, int ans)
{
    int x, i, j, visit[30][30];
    if(ans > total)
        total = ans;
    x = edge[node].size();
//    for(i = 0; i < n; ++i)
//        for(j = 0; j < n; +j)
//            visit[i][j] = conn[i][j];
    for(i = 0; i < x; ++i)
    {
        if(conn[node][edge[node][i]] == 0)
        {
            conn[node][edge[node][i]] = 1;
            conn[edge[node][i]][node] = 1;
            backtrack(conn, edge[node][i], ans + 1);
            conn[node][edge[node][i]] = 0;
            conn[edge[node][i]][node] = 0;
        }
    }
}

int main()
{
    int n, m, a, b, i, conn[30][30], ans;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
            break;
        ans = 0;
        total = 0;
        memset(conn, 0, sizeof(conn));
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        for(i = 0; i < n; ++i)
            backtrack(conn, i, ans);
        printf("%d\n", total);
        for(i = 0; i < n; ++i)
            edge[i].clear();
    }
    return 0;
}
