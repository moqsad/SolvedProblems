#include <cstdio>

int main()
{
    int t, n, cnt, i = 1;
    double s, p, b, ans;
    while(scanf("%d %d %lf", &t, &n, &b) == 3 && b != 0)
    {
        ans = 0;
        for(cnt = 0; cnt < t; ++cnt)
        {
            scanf("%lf %lf", &s, &p);
            ans += s * (1 - p / 100.00);
        }
        printf("Case %d: %.2lf\n\n", i++, ans / b);
    }
    return 0;
}
