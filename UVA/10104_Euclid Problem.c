#include <stdio.h>
long long int lastx, lasty;

int main()
{
    long long int a, b, x, y, r;
    while(scanf("%lld %lld", &a, &b) == 2)
    {
        x = a;
        y = b;
        while(y > 0)
        {
            r = x % y;
            x = y;
            y = r;
        }
        extended_gcd(a, b);
        printf("%lld %lld %lld\n", lastx, lasty, x);
    }
    return 0;
}

void extended_gcd(long long int a, long long int b)
{
    long long int x, y, quotient, temp;
    x = 0;
    y = 1;
    lastx = 1;
    lasty = 0;
    while(b != 0)
    {
        quotient = a / b;
        temp = b;
        b = a % b;
        a = temp;
        temp = x;
        x = lastx - quotient * x;
        lastx = temp;
        temp = y;
        y = lasty - quotient * y;
        lasty = temp;
    }
    return (lastx, lasty);
}
