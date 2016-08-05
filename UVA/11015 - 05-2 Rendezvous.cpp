#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

char arr[25][15];
int ans[25][25];

int n;

void func(void)
{
    int i, j, k;
    for(k = 1; k <= n; ++k)
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
}

int main()
{
    int m, i, j, a, b, c, x, y, total, cnt = 0;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
            break;

        for(i = 1; i <= n; ++i)
            scanf("%s", &arr[i]);

        for(i = 1; i <= n; ++i)
        {
            for(j = 1; j <= n; ++j)
                ans[i][j] = 1000000000;
            ans[i][i] = 0;
        }

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            ans[a][b] = c;
            ans[b][a] = c;
        }
        func();
        total = 1000000000;
        y = 1;
        for(i = 1; i <= n; ++i)
        {
            x = 0;
            for(j = 1; j <= n; ++j)
                x += ans[i][j];

            if(x < total)
            {
                total = x;
                y = i;
            }
        }
        printf("Case #%d : %s\n", ++cnt, arr[y]);
    }
    return 0;
}
