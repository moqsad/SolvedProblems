#include <stdio.h>
#include <math.h>
int main()
{
    long long int n, x, a, b, p, q;
    while(1)
    {
        scanf("%lld", &n);
        if(n == 0)
            break;
        x = ceil(sqrt(n));
        p = x - 1;
        q = p * p;
        n -= q;
        a = n / x;
        b = n % x;
        if(b == 0)
            b = x;
        if(x % 2 == 0)
        {
            if(a == 0 || b == x)
                printf("%lld %lld\n", b, x);
            else
                printf("%lld %lld\n", x, x - b);
        }
        else
        {
            if(a == 0 || b == x)
                printf("%lld %lld\n", x, b);
            else
                printf("%lld %lld\n", x - b, x);
        }
    }
    return 0;
}
