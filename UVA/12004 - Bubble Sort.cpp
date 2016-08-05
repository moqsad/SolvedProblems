#include <cstdio>
#include <cmath>


double ans[100010];

int main()
{
    int n, cnt, t, i;
    double x;
    for(i = 2; i <= 100000; ++i)
        ans[i] = ans[i - 1] + (double)(i - 1) / 2.0;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        if(ans[n] == floor(ans[n]))
            printf("Case %d: %.0lf\n", cnt, ans[n]);
        else
        {
            printf("Case %d: %.0lf/2\n", cnt, 2.0 * ans[n]);
        }
    }
    return 0;
}
//4999850001/2
