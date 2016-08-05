#include <stdio.h>
int main()
{
    long long int a, b, temp, i;
    while(scanf("%lld %lld", &a, &b) == 2)
    {
        printf("[%lld;", a / b);
        i = 0;
        while(a % b > 0)
        {
            if(i > 0)
                printf(",");
            temp = b;
            b = a % b;
            a = temp;
            printf("%lld", a / b);
            ++i;
        }
        printf("]\n");
    }
    return 0;
}
