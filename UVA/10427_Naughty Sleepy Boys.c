#include <stdio.h>
#include <math.h>
int main()
{
    long long int n, p, ans, i, count, det, k;
    while(scanf("%lld", &n) == 1)
    {
        p = 0;
        while(1)
        {
            if(n > 9)
            {
                ++p;
                n -= 9;
            }
            else
            {
                ++p;
                break;
            }
            if(n > 180)
            {
                ++p;
                n -= 180;
            }
            else
            {
                ++p;
                break;
            }
            if(n > 2700)
            {
                ++p;
                n -= 2700;
            }
            else
            {
                ++p;
                break;
            }
            if(n > 36000)
            {
                ++p;
                n -= 36000;
            }
            else
            {
                ++p;
                break;
            }
            if(n > 450000)
            {
                ++p;
                n -= 450000;
            }
            else
            {
                ++p;
                break;
            }
            if(n > 5400000)
            {
                ++p;
                n -= 5400000;
            }
            else
            {
                ++p;
                break;
            }
            if(n > 63000000)
            {
                ++p;
                n -= 63000000;
            }
            else
            {
                ++p;
                break;
            }
            ++p;
            break;
        }
        ans = 1;
        for(count = 2; count <= p; ++count)
            ans *= 10;
            det = ans;
        ans += ceil((double)n / (double)p) - 1;
        k = n % p;
        if(k == 0)
            k = p;
        for(i = 2; i <= k; ++i)
            det /= 10;
        ans = ans / det;
        printf("%lld\n", ans % 10);
    }
    return 0;
}
