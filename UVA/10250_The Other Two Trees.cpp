#include <cstdio>

int main()
{
    double a, b, c, d, x1, y1, x2, y2;
    while(scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2) == 4)
    {
        a = (x1 + x2) / 2;
        b = (y1 + y2) / 2;
        c = a - x1;
        d = b - y1;
        printf("%.10lf %.10lf %.10lf %.10lf\n", a - d, b + c, a + d, b - c);
    }
    return 0;
}
