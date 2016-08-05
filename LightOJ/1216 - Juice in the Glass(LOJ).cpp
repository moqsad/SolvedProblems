#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

#define PI acos(-1)

int main()
{
    int t, cnt;
    double r1, r2, h, p, o, R, ans;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf %lf %lf %lf", &r1, &r2, &h, &p);
        o = h / (r1 - r2) * r2;
        R = p * (r1 - r2) / h + r2;
        ans = 1.0 / 3.0 * PI * ((o + p) * R * R - o * r2 * r2);
        printf("Case %d: %.8lf\n", cnt, ans);
    }
    return 0;
}
