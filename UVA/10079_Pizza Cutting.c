#include <stdio.h>
int main()
{
    long long int n, ans;
    while(1)
    {
        scanf("%lld", &n);
        if(n < 0)
        break;
        ans = n * (n + 1) / 2 + 1;
        printf("%lld\n", ans);
    }
    return 0;
}
