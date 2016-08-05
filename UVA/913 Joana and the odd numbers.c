#include <stdio.h>
int main()
{
    long long int n, k, p;
    while(scanf("%lld", &n) == 1)
    {
        k = n / 2;
        k = k * (2 + (k - 1) * 2);
        k = k / 2;
        p = k + n - 2;
        k = 3 * (1 + (p - 1) * 2) + 6;
        printf("%lld\n", k);
    }
    return 0;
}
