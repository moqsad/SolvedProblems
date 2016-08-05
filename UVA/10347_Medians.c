#include <stdio.h>
#include <math.h>
int main()
{
    double u, v, w, x, s;
    while(scanf("%lf %lf %lf", &u, &v, &w) == 3)
    {
        s = (u + v + w) / 2;
        x = s * (s - u) * (s - v) * (s - w);
        if(x <= 0)
            printf("-1\n");
        else
            printf("%.3lf\n", 4.0 / 3.0 * pow(x, .5));
    }
    return 0;
}
