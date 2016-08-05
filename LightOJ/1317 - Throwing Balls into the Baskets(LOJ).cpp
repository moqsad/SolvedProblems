#include <stdio.h>

int t, cnt;
double n, k;

int main()
{
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf %lf %lf", &n, &k, &k);
        n = n * k;
        scanf("%lf", &k);
        printf("Case %d: %.8lf\n", cnt, n * k);
    }
    return 0;
}
