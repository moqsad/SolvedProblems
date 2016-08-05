#include <cstdio>

int main()
{
    long long cnt = 0, x, y, n, sum, i;
    while(scanf("%lld", &n) == 1)
    {
        if(n == 0)
            break;
        sum = 0;
        x = n / 3;
        for(i = 1; i < x; ++i)
        {
            y = n - i;
            if(y % 2 == 0)
                y -= 1;
            sum += y / 2 - i;
        }
        printf("Case %lld: %lld\n", ++cnt, sum);
    }
    return 0;
}
