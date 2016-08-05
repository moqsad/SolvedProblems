#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 2 * (acos(0))
int main()
{
    double r, angle, a1, a2;
    char arr[5];
    while(scanf("%lf %lf %s", &r, &angle, arr) == 3)
    {
        if(strcmp(arr, "min") == 0)
            angle = (PI / 180) * (angle / 60.0);
        else
            angle = (PI / 180) * angle;
        if(angle > PI)
            angle = 2 * PI - angle;
        a1 = (r + 6440) * angle;
        a2 = (r + 6440) * sin(angle / 2.0) * 2;
        printf("%.6lf %.6lf\n", a1, a2);
    }
    return 0;
}
