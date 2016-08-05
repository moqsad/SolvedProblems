#include <stdio.h>
int main()
{
    long long int a, x;
    while(1)
    {
        scanf("%lld", &a);
        if(a == 0)
            break;
        x = a / 9;
        if(a % 9 > 0)
            printf("%lld\n", a + x);
        else
            printf("%lld %lld\n", a + x - 1, a + x);
    }
    return 0;
}
