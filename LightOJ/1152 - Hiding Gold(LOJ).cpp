#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

#define sz 22

struct data
{
    int a, b;
} match[sz][sz];

int visit[sz][sz], m, n, p[] = {-1, 1, 0, 0}, q[] = {0, 0, -1, 1};

char arr[sz][sz];

int dfs(int r, int c)
{
    int i, x, y;

    for(i = 0; i < 4; ++i)
    {
        x = p[i] + r;
        y = q[i] + c;

        if(x >= 0 && x < m && y >= 0 && y < n)
        {
            if(!visit[x][y] && arr[x][y] == '*')
            {
//                printf("__________");
                visit[x][y] = 1;
                if((match[x][y].a == -1) || dfs(match[x][y].a, match[x][y].b))
                {
                    match[x][y].a = r;
                    match[x][y].b = c;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int t, cnt, ans, sum, i, j;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &m, &n);

        for(i = 0; i < m; ++i)
        {
            scanf("%s", arr[i]);
            for(j = 0; j < n; ++j)
            {
                match[i][j].a = -1;
                match[i][j].b = -1;
            }
        }

        sum = ans = 0;
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
            {
                if(arr[i][j] == '*')
                {
                    memset(visit, 0, sizeof(visit));
                    if(dfs(i, j))
                        ++sum;
                    else
                        ++ans;
                }
            }
//        printf("%d__________\n", ans);
        printf("Case %d: %d\n", cnt, ans + sum / 2);
    }
    return 0;
}

