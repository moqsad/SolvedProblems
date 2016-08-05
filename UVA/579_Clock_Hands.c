#include <stdio.h>
#include <math.h>
int main()
{
    double a, b, ans;
    while(1)
    {
        scanf("%lf:%lf", &a, &b);
        if(a == 0 && b == 0)
        break;
        ans = fabs((b / 5 - a - b / 60) * 30);
        if(ans > 180)
        ans = 360 - ans;
        printf("%.3lf\n", ans);
    }
    return 0;
}
