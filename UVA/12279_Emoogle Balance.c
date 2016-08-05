#include <stdio.h>
int main()
{
    int n, count, i, a, j = 0;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        ++j;
        i = 0;
        for(count = 1; count <= n; ++count)
        {
            scanf("%d", &a);
            if(a == 0)
                ++i;
        }
        printf("Case %d: %d\n", j, (n - i) - i);
    }
    return 0;
}
