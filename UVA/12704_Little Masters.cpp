#include <cstdio>
#include <cmath>

int main()
{
    int t, cnt;
    double dist, x, y, r;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%lf %lf %lf", &x, &y, &r);
        dist = sqrt(x * x + y * y);
        printf("%.2lf %.2lf\n", r - dist, r + dist);
    }
    return 0;
}
