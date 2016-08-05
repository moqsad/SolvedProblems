#include <cstdio>
#include <cmath>

bool ans[35], prime[35];
long long power[35];

long long func(long long n)
{
    if(n == 1)
        return power[1] = 2;
    else if(power[n] > 0)
        return power[n];
    else
        return power[n] = 2 * func(n - 1);
}

int main()
{
    long long i, j, x, y, p;
    prime[2] = prime[3] = prime[5] = prime[7] = prime[11] = prime[13] = prime[17] = prime[19] = prime[23] = prime[29] = 1;
//    for(j = 2; j < 32; ++j)
//    {
//        x = func(j) - 1;
//        y = sqrt(x) + 2;
//        i = 2;
//        p = 1;
//        while(i < y)
//        {
//            if(x % i == 0)
//            {
//                p = 0;
//                break;
//            }
//            ++i;
//        }
//        if(p == 1)
//            ans[j] = 1;
//    }
    ans[2] = ans[3] = ans[5] = ans[7] = ans[13] = ans[17] = ans[19] = ans[31] = 1;
    //why in this process uva runtime is greater than previous method??????................
    while(scanf("%lld", &p) == 1)
    {
        if(p == 0)
            break;
        if(ans[p] == 1)
            printf("Perfect: %lld!\n", func(p - 1) * (func(p) - 1));
        else if(prime[p] == 1)
            printf("Given number is prime. But, NO perfect number is available.\n");
        else
            printf("Given number is NOT prime! NO perfect number is available.\n");
    }
    return 0;
}
