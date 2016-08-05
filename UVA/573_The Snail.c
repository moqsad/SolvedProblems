#include <stdio.h>
int main()
{
    double a, b, c, d, t, x, y;
    int cnt, i;
    while(1)
    {
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        if(a == 0)
            break;
        t = 0;
        x = b * d / 100;
        y = b;
        cnt = 0;
        while(1)
        {
            t += y;
            ++cnt;
            if(t > a)
            {
                printf("success on day %d\n", cnt);
                break;
            }
            y = b - c - x * cnt;
            if(b - x * cnt < 0)
                y = - c;

            if(t < c)
            {
                printf("failure on day %d\n", cnt);
                break;
            }
        }
    }
    return 0;
}
