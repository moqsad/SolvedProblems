#include <stdio.h>
int main()
{
    int n, i, j, p, k;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        while(1)
        {
            k = 0;
            for(i = 1; i <= 22; ++i)
                if(i * i * i == n)
                {
                    k = 1;
                    printf("%d 0\n", i);
                    break;
                }
            if(k == 1)
                break;
            p = 1;
            for(i = 1; i < 61; ++i)
            {
                for(j = 1; j < 61; ++j)
                    if(i * i * i - j * j * j == n)
                    {
                        p = 0;
                        printf("%d %d\n", i, j);
                        break;
                    }
                if(p == 0)
                    break;
            }
            if(p == 1)
            {
                printf("No solution\n");
                break;
            }
            else
                break;
        }
    }
    return 0;
}
