#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using  namespace std;

#define PI acos(-1)

int main()
{
    int cnt, t, i;
    double ab, ac, bc, ratio_, a, b, c, beg, end_, mid, x, area, area_beg, area_mid;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &ratio_);
        a = acos((ab * ab + ac * ac - bc * bc) / 2 / ab / ac);
        b = acos((ab * ab + bc * bc - ac * ac) / 2 / ab / bc);
        c = PI - a - b;
        area = .5 * sin(b) * ab * bc;
        beg = 0.0;
        end_ = ab;
//        printf("%lf________\n", area);

        for(i = 0; i < 100; ++i)
        {
            mid = (beg + end_) / 2.00;
//            area_beg = .5 * sin(b) * beg * (beg / sin(c) * sin(a)) / (area - area_beg);
            area_mid = .5 * sin(b) * mid * (mid / sin(c) * sin(a));
            area_mid = area_mid / (area - area_mid);
//            printf("%lf %lf______\n", area_mid, ratio_);
            if(ratio_ > area_mid)
            {
                beg = mid;
            }
            else
                end_ = mid;
        }
        printf("Case %d: %.8lf\n", cnt, mid);
    }
    return 0;
}
