#include <stdio.h>
int main()
{
    double a, s, t, u, v;
    int n, count = 0;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
        break;
        ++count;
        switch(n)
        {
            case 1 : scanf("%lf %lf %lf", &u, &v, &t);
                    s = (u + v) / 2 * t;
                    a = (v - u) / t;
                    printf("Case %d: %.3lf %.3lf\n", count, s, a);
                    break;
            case 2 : scanf("%lf %lf %lf", &u, &v, &a);
                    s = (v * v - u * u) / (2 * a);
                    t = (v - u) / a;
                    printf("Case %d: %.3lf %.3lf\n", count, s, t);
                    break;
            case 3 : scanf("%lf %lf %lf", &u, &a, &s);
                    v = sqrt(u * u + 2 * a * s);
                    t = (v - u) / a;
                    printf("Case %d: %.3f %.3f\n", count, v, t);
                    break;
            case 4 : scanf("%lf %lf %lf", &v, &a, &s);
                    u = sqrt(v * v - 2 * a * s);
                    t = (v - u) / a;
                    printf("Case %d: %.3lf %.3lf\n", count, u , t);
                    break;
        }
    }
    return 0;
}
