#include <cstdio>
#include <cmath>

int main()
{
    int n, i, p;
    double gx, gy, dx, dy, a, b, x, y, gdist, ddist;
    while(scanf("%d", &n) == 1)
    {
        scanf("%lf %lf %lf %lf", &gx, &gy, &dx, &dy);
        p = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%lf %lf", &a, &b);
            if(p == 0)
            {
                x = gx - a;
                y = gy - b;
                gdist = sqrt(x * x + y * y);
                x = dx - a;
                y = dy - b;
                ddist = sqrt(x * x + y * y);
//                printf("%lf %lf__________\n", gdist, ddist);
                if(ddist >= 2 * gdist)
                {
                    p = 1;
                    printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", a, b);
                }
            }
        }
        if(p == 0)
            printf("The gopher cannot escape.\n");
    }
    return 0;
}
