#include <cstdio>
#include <cmath>
#define PI 2*acos(0)

int main()
{
    int t, cnt;
    double d, l, a;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%lf %lf", &d, &l);
        a = sqrt(l * l / 4.0 - d * d / 4.0);
        printf("%.3lf\n", PI * a * l / 2.0);
    }
    return 0;
}
