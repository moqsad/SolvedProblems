#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

double a[1010], b[1010], high[1010];

int main()
{
    int i, j, cnt, t, n, p;
    double x, y, dist, total;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d", &n);
        total = 0;
        for(i = 0; i < n; i++)
            high[i] = 124352344567657786.0;
        for(i = 0; i < n; ++i)
        {
            scanf("%lf %lf", &a[i], &b[i]);
        }
        p = 1;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                if(i != j)
                {
                    x = a[i] - a[j];
                    y = b[i] - b[j];
                    dist = sqrt(x * x + y * y);
                    if(dist >= 2)
                    {
                        if(dist - 1 < high[i])
                            high[i] = dist - 1;
                    }
                    else
                    {
                        p = 0;
                        break;
                    }
                }
            }
            if(p == 0)
                break;
        }
        if(p == 1)
        {
            for(i = 0; i < n; ++i)
                if(high[i] > total)
                    total = high[i];
            printf("%.6lf\n", total);
        }
        else
            printf("%.6lf\n", -1.0);
    }
    return 0;
}
