#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int t, cnt;
    double a, b, x1, x2, max_, sub, min_;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        max_ = 0;
        scanf("%lf %lf", &a, &b);
        min_ = min(a, b);
        sub = sqrt(16 * (a + b) * (a + b) - 4 * 12 * a * b);
        x1 = (4 * (a + b) + sub) / 24.0;
        x2 = (4 * (a + b) - sub) / 24.0;
        if(x1 >= 0 && x1 <= min_)
            max_ = x1 * (a - 2 * x1) * (b - 2 * x1);
        if(x2 >= 0 && x2 <= min_)
            max_ = max(max_, x2 * (a - 2 * x2) * (b - 2 * x2));
        printf("Case %d: %.8lf\n", cnt, max_);
    }
    return 0;
}
