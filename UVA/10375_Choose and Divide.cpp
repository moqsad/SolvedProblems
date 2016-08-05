#include <cstdio>

int main()
{
    int i, cnt;
    double p, q, r, s, a, b, c, d, x, y, z, ans;
    while(scanf("%lf %lf %lf %lf", &p, &q, &r, &s) == 4)
    {
        ans = 1;
        x = (q > p - q) ? q : p - q;
        y = (q < p - q) ? q : p - q;
        z = x + 1;
        a = (s > r - s) ? s : r - s;
        b = (s < r - s) ? s : r - s;
        c = a + 1;
        cnt = (y < b) ? y : b;
        for(i = 1; i <= cnt; ++i)
        {
            ans *= z++ / c++;
        }
        d = cnt;
        while(z <= p)
            ans *= z++ / ++d;
        d = cnt;
        while(c <= r)
            ans /= c++ / ++d;
        printf("%.5lf\n", ans);
    }
    return 0;
}
