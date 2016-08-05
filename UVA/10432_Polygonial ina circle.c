#include <stdio.h>
#include <math.h>
#define PI 2 * (acos(0))
int main()
{
    double r, n, x;
    while(scanf("%lf %lf", &r, &n) == 2)
    {
        x = PI * r * r / n - .5 * r * r * sin(PI * 2 / n);
        printf("%.3lf\n",PI * r * r - n * x);
    }
    return 0;
}
