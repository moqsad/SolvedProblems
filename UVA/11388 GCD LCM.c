#include <stdio.h>
int main()
{
    long long int n, x, y, a, b, count;
    scanf("%lld", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%lld %lld", &x, &y);
        if(x == 0 || y % x != 0)
        printf("-1\n");
        else
        printf("%lld %lld\n", x, y);
    }
    return 0;
}
