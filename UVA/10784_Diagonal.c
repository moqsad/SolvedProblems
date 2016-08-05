#include <stdio.h>
#include <math.h>
int main()
{
    long long n, ans, i = 0;
    while(1)
    {
        scanf("%lld", &n);
        if(n == 0)
            break;
        ans = ceil((3 + sqrt(9 + 8 * n)) / 2);
        ++i;
        printf("Case %lld: %lld\n", i, ans);
    }
    return 0;
}
