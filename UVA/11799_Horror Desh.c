#include <stdio.h>
int main()
{
    int t, n, count, x, a, i;
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%d", &n);
        x = -1;
        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &a);
            if(a > x)
                x = a;
        }
        printf("Case %d: %d\n", count, x);
    }
    return 0;
}
