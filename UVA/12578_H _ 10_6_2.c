#include <stdio.h>
#define PI acos(-1)
int main()
{
    double l, w, r, cnt, t, a;
    scanf("%lf", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf", &l);
        r = l / 5;
        w = l * 3 / 5;
        a = PI * r * r;
        printf("%.2lf %.2lf\n", a, l * w - a);
    }
    return 0;
}
