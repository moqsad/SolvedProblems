#include <stdio.h>
int main()
{
    long long int n, k, cnt, x, y, sum;
    while(scanf("%lld %lld", &n, &k) == 2)
    {
        if(k == 0 && n == 0)
        break;
        if(k == 0 || n == 0)
            printf("1\n");
        else
        {
            x = k < n - k ? k : n - k;
            y = n - x + 1;
            sum = 1;
            for(cnt = 1; cnt <= x; ++cnt)
            {
                sum = (sum * y) / cnt;
                ++y;
            }
            printf("%lld\n", sum);
        }
    }
    return 0;
}
