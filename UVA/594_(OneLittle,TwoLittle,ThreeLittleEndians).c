#include <stdio.h>
#include <math.h>

int main()
{
    long long int a, cnt, digit[100], tag, b, num[100], i, x, p, sum;
    double d;
    while(scanf("%lld", &a) == 1)
    {
        sum = 0;
        b = a;
        if(a < 0)
            a = - a;
        cnt = 0;
        while(a != 0)
        {
            digit[cnt++] = a % 2;
            a /= 2;
        }
        tag = cnt;
        for(cnt = tag; cnt < 32; ++cnt)
        {
            digit[cnt] = 0;
        }
        i = 31;
        for(cnt = 0; cnt < 32; ++cnt)
        {
            num[i] = digit[cnt];
            --i;
        }
        if(b < 0)
        {
            for(i = 31; i >= 0; --i)
            {
                if(num[i] == 0)
                    num[i] = 1;
                else
                {
                    num[i] = 0;
                }
            }
            for(i = 31; i >= 0; --i)
            {
                if(num[i] == 1)
                    num[i] = 0;
                else
                {
                    num[i] = 1;
                    break;
                }
            }
        }
        x = 24;
        for(cnt = 0; cnt < 32; ++cnt)
        {
            if(cnt % 8 == 0 && cnt > 0)
            {
                x -= 16;
            }
            digit[cnt + x] = num[cnt];
        }
        p = 0;
        if(digit[0] == 1)
        {
            p = 1;
            for(i = 31; i >= 0; --i)
            {
                if(digit[i] == 0)
                    digit[i] = 1;
                else
                {
                    digit[i] = 0;
                    break;
                }
            }
            for(i = 31; i >= 0; --i)
            {
                if(digit[i] == 0)
                      digit[i] = 1;
                else
                {
                    digit[i] = 0;
                }
            }
        }
        a = 30;
        for(cnt = 1; cnt < 32; ++cnt)
        {
            if(digit[cnt] == 1)
                sum += pow(2, a);
            --a;
        }
        if(p == 0)
            printf("%lld converts to %lld\n", b, sum);
        else
            printf("%lld converts to -%lld\n", b, sum);
    }
    return 0;
}
