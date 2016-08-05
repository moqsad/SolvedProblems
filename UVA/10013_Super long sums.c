#include <stdio.h>
int  a[1000100][1], b[1000100][1], ans[1000100][1];
int main()
{
    int i, count, n, x, m, j, y, p;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%d", &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a[i][0], &b[i][0]);
        }
        y = 0;
        for(j = i - 1; j >= 0; --j)
        {
            x = a[j][0] + b[j][0] + y;
            if(x >= 10)
            {
                y = x / 10;
                x = x % 10;
            }
            else
                y = 0;
            ans[j][0] = x;
        }
        for(j = 0; j < i; ++j)
            printf("%d", ans[j][0]);
        if(count < n)
            printf("\n\n");
        else
            printf("\n");
    }
    return 0;
}
