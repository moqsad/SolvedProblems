#include <stdio.h>

int main()
{
    int t, cnt, n, i;
    double pre, pres, nn;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        nn = n;
        pre = 0;
        for(i = 1; i < n; ++i)
        {
            pres = pre + nn / (double)i;
            pre = pres;
        }
        printf("Case %d: %.8lf\n", cnt, pre + 1.0);
    }
    return 0;
}
