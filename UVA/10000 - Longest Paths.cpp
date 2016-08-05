#include <cstdio>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector <int> edge[102];
int d[102];

void dfs(int start)
{
    int i, x, y;
    x = edge[start].size();
    for(i = 0; i < x; ++i)
    {
        y = edge[start][i];
        if(d[start] + 1 > d[y])
        {
            d[y] = d[start] + 1;
            dfs(y);
        }
    }
}

int main()
{
    int n, a, b, s, i, max_, node, cnt = 0;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        scanf("%d", &s);
        while(scanf("%d %d", &a, &b) == 2)
        {
            if(a == 0 && b == 0)
                break;
            edge[a].push_back(b);
        }

        memset(d, 0, sizeof(d));

        dfs(s);

        max_ = 0;
        node = s;
        for(i = 1; i <= n; ++i)
        {
            if(d[i] > max_)
            {
                max_ = d[i];
                node = i;
            }
            edge[i].clear();
        }
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++cnt, s, max_, node);
    }
    return 0;
}
