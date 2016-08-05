#include <stdio.h>
#include <math.h>
int main()
{
    double x, y;
    int a, b;
    while(1)
    {
        scanf("%lf %lf", &x, &y);
        if(x == 0 && y == 0)
        break;
        if(x != y)
        {
        a = sqrt(x);
        b = sqrt(y);
        if(a == sqrt(x))
        printf("%d\n", b - a + 1);
        else
        printf("%d\n", b - a);
        }
        else
        {
            a = sqrt(x);
            if(a == sqrt(x))
            printf("1\n");
            else
            printf("0\n");
        }
    }
    return 0;
}
