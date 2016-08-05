#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793
int main()
{
    double x1, y1, x2, y2, x3, y3, r, a, b, c;
    while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6)
    {
        a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        r = a * b * c / sqrt((a + b + c) * (b + c - a) * (c + a - b) * (a + b - c));
        printf("%.2lf\n", 2 * PI * r);
    }
    return 0;
}
