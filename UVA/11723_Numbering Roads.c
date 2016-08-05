#include <stdio.h>
#include <math.h>
int main()
{
    double r, n;
    int i = 0;
    while(1)
    {
        scanf("%lf %lf", &r, &n);
        if(r == 0 && n == 0)
            break;
        if(r / n > 27)
            printf("Case %d: impossible\n", ++i);
        else
            printf("Case %d: %d\n", ++i, (int)(ceil(r / n) - 1));
    }
        return 0;
}
