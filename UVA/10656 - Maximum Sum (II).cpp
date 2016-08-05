#include <cstdio>
#include <cstring>

int main()
{
    int n, i, num[1010], p;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        p = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &num[i]);
            if(num[i] > 0)
            {
                p = 1;
                printf("%d", num[i]);
                ++i;
                break;
            }
        }
        for(i = i; i < n; ++i)
        {
            scanf("%d", &num[i]);
            if(num[i] > 0)
                printf(" %d", num[i]);
        }
        if(p == 0)
            printf("0");
        printf("\n");
    }
    return 0;
}
