#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int t, cnt;
    double v1, v2, v3, a1, a2, S, T, D, x, y;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);
        D = v1 * v1 / 2.0 / a1 + v2 * v2 / 2.0 / a2;
        x = v1 / a1;
        y = v2 / a2;
        T = max(x, y);
        S = T * v3;
        printf("Case %d: %.8lf %.8lf\n", cnt, D, S);
    }
    return 0;
}
