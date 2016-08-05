#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

long long num[20];

int main()
{
    long long t, cnt, i, x, y;
    double a, sum;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        sum = 0;
        for(i = 0; i < 12; ++i)
        {
            scanf("%lf", &a);
            sum += a;
        }
        sum /= 12.0;
        x = (int)sum;
        y = round((sum - x) * 100.0);
        i = 0;
        while(x > 0)
        {
            num[i++] = x % 10;
            x /= 10;
        }

        printf("%lld $", cnt);
        if(i == 0)
            printf("0");
        while(i--)
        {
        printf("%lld", num[i]);
            if(i == 3)
                printf(",");
        }
        printf(".");
        if(y < 10)
            printf("0");
        printf("%lld\n", y);
    }
    return 0;
}
