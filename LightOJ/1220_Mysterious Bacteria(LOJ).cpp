#include <cstdio>
#include <cstring>
#include <cmath>

int main()
{
    long long t, cnt, n, i, j, k, sum, x, y, p;
    scanf("%lld", &t);
    for(cnt = 1; cnt<=t; ++cnt)
    {
        scanf("%lld", &n);
        if(n > 0)
            y = n;
        else
            y = -n;
        x = sqrt(y) + 2;
        p = 0;
        if(n > 0)
        {
            for(i = 2; i < x; ++i)
            {
                sum = 1;
                j = 0;
                while(sum < y)
                {
                    sum *= i;
                    ++j;
                }
                if(sum == y)
                {
                    p = 1;
                    break;
                }
            }
            if(p == 0)
                j = 1;
        }

        if(n < 0)
        {
//            printf("%lld______\n", n);
            x = -x;
            p = 0;
            for(i = -2; i > x; --i)
            {
                sum = 1;
                j = 0;
                while(sum > n)
                {
                    sum *= i;
//                    printf("%lld %lld\n", sum, i);
                    ++j;
                }
                if(sum == n)
                {
                    p = 1;
                    break;
                }
            }
            if(p == 0)
                j = 1;
        }

        printf("Case %lld: %lld\n", cnt, j);
    }
    return 0;
}
