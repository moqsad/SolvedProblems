#include <stdio.h>
int main()
{
    long long int ans, a, count;
    while(scanf("%lld", &a) == 1)
    {
        if(a >= 8 && a <= 13)
        {
            ans = 1;
            for(count = 1; count <= a; ++count)
            ans *= count;
            printf("%lld\n", ans);
        }
        else if(a < 0)
        {
            if(a % 2 == 0)
            printf("Underflow!\n");
            else
            printf("Overflow!\n");
        }
        else if(a < 8)
        printf("Underflow!\n");
        else
        printf("Overflow!\n");
    }
    return 0;
}
