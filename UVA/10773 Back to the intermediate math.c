#include <stdio.h>
#include <math.h>
int main()
{
    int n, count;
    double d, boat, man, tr, tmin;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%lf %lf %lf", &d, &boat, &man);
        if(boat == 0 || man == 0 || boat >= man)
            printf("Case %d: can\'t determine\n", count);
        else
        {
            tr = d / man / cos(acos(- boat / man) - acos(0));
            tmin = d / man;
            printf("Case %d: %.3lf\n", count, tr - tmin);
        }
    }
    return 0;
}
