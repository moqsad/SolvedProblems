#include <stdio.h>
#include <math.h>
#define PI 2 * (acos(0))
int main()
{
    double l, w, h, angle, k;
    while(scanf("%lf %lf %lf %lf", &l, &w, &h, &angle) == 4)
    {
        if(tan(angle * PI / 180.0) <= h / l)
        {
        k = l * tan(angle * PI / 180.0);
        printf("%.3lf\n", l * w * h - .5 * k * l * w);
        }
        else
        {
            k = h * tan(PI / 2 - angle * PI / 180.0);
            printf("%.3lf\n", .5 * k * h * w);
        }
    }
    return 0;
}
