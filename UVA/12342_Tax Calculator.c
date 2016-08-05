#include <stdio.h>
#include <math.h>
int main()
{
    double a, ans;
    int n, cnt;
    scanf("%d", &n);
    for(cnt = 1; cnt <= n; ++cnt)
    {
        while(1)
        {
            scanf("%lf", &a);
            ans = 0;
                a -= 180000;
                if(a <= 0)
                break;
                if(a >= 300000)
                    ans = 30000;
                else
                    ans = a * .1;
                a -= 300000;
                if(a <= 0)
                    break;
                if(a >= 400000)
                    ans += 60000;
                else
                    ans += a * .15;
                a -= 400000;
                if(a <= 0)
                    break;
                if(a >= 300000)
                    ans += 60000;
                else
                    ans += a * .2;
                a -= 300000;
                if(a <= 0)
                    break;
                ans += a * .25;
                break;
        }
        if(ans > 0 && ans < 2000)
        ans = 2000;
        printf("Case %d: %.lf\n", cnt, ceil(ans));
    }
    return 0;
}
