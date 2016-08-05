#include <stdio.h>
int main()
{
    long long int s, d, k, n;
    while(scanf("%lld %lld", &s, &d) == 2)
    {
        k = (s - 1) * (s) / 2;
        n = (-1 + sqrt(1 + 8 * (d + k))) / 2;
        --n;
        while(n * (n + 1) < (d + k) * 2)
        ++n;
        printf("%lld\n", n);
    }
    return 0;
}
