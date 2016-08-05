#include <stdio.h>
int main()
{
    long long int a, b, ans;
    while(scanf("%lld %lld", &a, &b) == 2)
    {
        ans = b - a;
        if(ans < 0)
        ans = -ans;
        printf("%lld\n", ans);
    }
    return 0;
}
