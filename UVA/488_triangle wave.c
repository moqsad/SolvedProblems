#include <stdio.h>
int main()
{
    int a, b, c, count, d, i, n;
    scanf("%d", &n);
    for(i = 1; i <= n; ++i)
    {
    scanf("%d %d", &a, &b);
    d = 1;
    while(d <= b)
    {
        for(count = 1; count <= a; ++count)
        {
            for(c = 1; c <= count; ++c)
            {
                printf("%d", count);
            }
            printf("\n");
        }
        for(count = a - 1; count > 0; --count)
        {
            for(c = 1; c <= count; ++c)
            {
                printf("%d", count);
            }
            printf("\n");
        }
        if(d < b)
        printf("\n");
        ++d;
    }
    if(i < n)
    printf("\n");
    }
    return 0;
}
