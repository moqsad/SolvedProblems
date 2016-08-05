#include <cstdio>
#include <cmath>

int main()
{
    int n, i, cnt;
    double x, y, z, a;
    while(scanf("%d %lf", &n, &a) == 2)
    {
        if(n == 0)
            break;
        i = 0;
        for(cnt = 0; cnt < n; ++cnt)
        {
            scanf("%lf %lf", &x, &y);
            z = sqrt(x * x + y * y);
            if(z <= a)
            {
                z = sqrt(x * x + (a - y) * (a - y));
                if(z <= a)
                {
                    z = sqrt((a - x) * (a - x) + y * y);
                    if(z <= a)
                    {
                        z = sqrt((a - x) * (a - x) + (a - y) * (a - y));
                        if(z <= a)
                            ++i;
                    }
                }
            }
        }
        printf("%.5lf\n", (double)i / (double)n * a * a);
    }
    return 0;
}
