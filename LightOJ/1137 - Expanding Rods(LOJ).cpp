#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define inf 1000000000000000.0

int main()
{
    int t, cnt, i;
    double l, n, c, lnew, s, e, mid, ans, angle;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf %lf %lf", &l, &n, &c);

        lnew = (1 + c * n) * l;

        s = 0.0;
        e = inf;
        for(i = 0; i < 100; ++i)
        {
            mid = (s + e) / 2;

            angle = 2.0 * asin(l / 2.0 / mid);

            ans = angle * mid;

            if(lnew < ans)
                s = mid;

            else if(lnew > ans)
                e = mid;

            else
                break;
        }

        printf("Case %d: %.8lf\n", cnt, mid - sqrt(mid * mid - l * l / 4.0));
    }
    return 0;
}

