#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int i;
    double x, y, c, mid, a1, b1, c1, a2, b2, c2, x1, y1, ans, s, e;
    while(scanf("%lf %lf %lf", &x, &y, &c) == 3)
    {
        s = 0;
        e = min(x, y);
        for(i = 0; i < 100; ++i)
        {
            mid = (s + e) / 2;

            x1 = sqrt(x * x - mid * mid);
            y1 = sqrt(y * y - mid * mid);

            a1 = x1;
            b1 = mid;
            c1 = mid * x1;

            a2 = - y1;
            b2 = mid;
            c2 = 0;

            ans = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);

            if(ans > c)
                s = mid;
            else if(ans < c)
                e = mid;
            else
                break;
        }
        printf("%.3lf\n", mid);
    }
    return 0;
}
