#include <stdio.h>
int main()
{
    long long int n, k, a, b, c, i, cnt, sum;
    scanf("%lld", &n);
    for(cnt = 1; cnt <= n; ++cnt)
    {
        sum = 0;
        scanf("%lld", &k);
        for(i = 1; i <= k; ++i)
        {
            scanf("%lld %lld %lld", &a, &b, &c);
            sum += a * c;
        }
        printf("%lld\n", sum);
    }
}
