#include <stdio.h>
#include <math.h>
int main()
{
    double k, a, b, c;
    while(scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        if(a == 0 && b == 0 && c == 0)
            printf("The radius of the round table is: %.3lf\n", 0);
        else
        {
            k = (a + b + c) / 2;
            printf("The radius of the round table is: %.3lf\n", sqrt(k * (k - a) * (k - b) * (k - c)) / k);
        }
    }
    return 0;
}
