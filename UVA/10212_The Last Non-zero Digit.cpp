#include<cstdio>
#include<cmath>

int main()
{
    long long a, b, ans;
    while(scanf("%lld %lld", &a, &b) == 2)
    {
        ans = 1;
        while(b--)
        {
            ans *= a--;
            while(ans % 10L == 0)
            {
            ans /= 10L;
//            printf("%lld________\n", ans);
            }
            ans %= 1000000000L;
//            printf("%lld++++++++\n", ans);
        }
        printf("%lld\n", ans % 10L);
    }
    return 0;
}
//3453322 456564
