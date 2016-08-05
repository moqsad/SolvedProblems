#include <stdio.h>
int main()
{
    int x, y, a, i, count, t, n;
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%d", &n);
        scanf("%d", &a);
        x = a;
        y = a;
        for(i = 2; i <= n; ++i)
        {
            scanf("%d", &a);
            if(a < x)
                x = a;
            else if(a > y)
                y = a;
        }
        printf("%d\n", 2 * (y - x));
    }
    return 0;
}
