#include <stdio.h>
#include <math.h>
int main()
{
    int count = 0;
    double a;
    while(1)
    {
        scanf("%lf", &a);
        if(a < 0)
            break;
        ++count;
        if(a == 0)
            printf("Case %d: 0\n", count);
            else
            printf("Case %d: %.lf\n", count, ceil(log(a) / log(2.0)));
    }
    return 0;
}
