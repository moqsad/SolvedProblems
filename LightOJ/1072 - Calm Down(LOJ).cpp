#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

#define PI acos(-1)

int main()
{
    int t, cnt;
    double R, n, r, angle;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf %lf", &R, &n);
        angle = PI / n;
        r = R * sin(angle) / (1 + sin(angle));
        printf("Case %d: %.8lf\n", cnt, r);
    }
    return 0;
}
