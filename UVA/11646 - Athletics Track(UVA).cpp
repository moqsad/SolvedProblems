#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, cnt = 0, i;    double angle, r, l, w, x, y, z, cx, cy, s, e, mid, peri;//mid hocche length & width ke joto dara gun korte hobe

    while(scanf("%d : %d", &a, &b) == 2)
    {
        s = 0;
        e = 205;
        for(i = 0; i < 100; ++i)
        {
            mid = (s + e) / 2;

            l = a * mid;
            w = b * mid;
            cx = l / 2;
            cy = w / 2;

            x = sqrt((cx - l) * (cx - l) + cy * cy);
            y = sqrt((cx - l) * (cx - l) + (cy - w) * (cy - w));
            z = w;
            angle = acos((x * x + y * y - z * z) / 2 / x / y);
            peri = 2 * l + 2 * x * angle;

            if(peri > 400)
                e = mid;
            else if(peri < 400)
                s = mid;
            else
                break;
        }
        printf("Case %d: %.8lf %.8lf\n", ++cnt, a * mid, b * mid);
    }
    return 0;
}
