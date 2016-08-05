#include <stdio.h>
int main()
{
    long long int count, a, b, c, n;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        if(a >= b  + c || b >= c + a || c >= a + b)
        printf("Case %lld: Invalid\n", count);
        else if(a == b && a == c)
        printf("Case %lld: Equilateral\n", count);
        else if(a == b || b == c || c == a)
        printf("Case %lld: Isosceles\n", count);
        else
        printf("Case %lld: Scalene\n", count);
    }
    return 0;
}
