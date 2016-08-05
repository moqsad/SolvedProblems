#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int i, t, cnt;
    double l, n, c, s, e, mid, lnew, R, ans;
    const double PI = acos(-1);
    while(scanf("%lf %lf %lf", &l, &n, &c) == 3)
    {
        if(c < 0)
            break ;
        lnew = (1 + c * n) * l;
        s = 0.0;
        e = PI / 2.0;
        for(i = 0; i < 100; ++i)
        {
            mid = (s + e) / 2;
            R = l / 2 / sin(mid);
            ans = 2 * R * mid;
            if(!(lnew <= ans))
                s = mid;
            else
                e = mid;
        }
        printf("%.3lf\n", R - R * cos(mid));
    }
    return 0;
}
