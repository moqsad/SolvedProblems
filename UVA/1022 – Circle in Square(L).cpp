#include <cstdio>
#include <cmath>
#define PI 2*acos(0)

int main()
{
    int cnt, t;
    double x, r;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf", &r);
        printf("Case %d: %.2lf\n", cnt, r * r * (4 - PI));
    }
    return 0;
}
