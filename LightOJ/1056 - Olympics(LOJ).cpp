#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

#define PI acos(-1)

int main()
{
    int t, cnt;
    double a, b, angle, factor;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf : %lf", &a, &b);
        angle = PI - 2 * atan(a / b);
        factor = 400.0 / (sqrt(a * a + b * b) * angle + 2 * a);
        printf("Case %d: %.8lf %.8lf\n", cnt, a * factor, b * factor);
    }
    return 0;
}

