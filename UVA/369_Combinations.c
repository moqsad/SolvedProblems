#include <stdio.h>
int main()
{
    long long int n, k, cnt, x, y, sum;
    scanf("%lld %lld", &n, &k);
    {
        if(k == 0 || n == 0)
                       printf("%lld things taken %lld at a time is 1 exactly.\n", n, k);
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
            printf("%lld things taken %lld at a time is %lld exactly.\n", n, k, sum);
        }
    }
    return 0;
}
