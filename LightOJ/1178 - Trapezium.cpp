#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, cnt;
    double a, b, c, d, s, h, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);

        if(a > c)
            x = a - c;
        else
            x = c - a;

        s = (x + b + d) / 2;
        h = 2 * sqrt(s * (s - b) * (s - d) * (s - x)) / x;
        printf("Case %d: %.7lf\n", cnt, .5 * (a + c) * h);
    }
    return 0;
}
