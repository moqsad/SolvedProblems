#include <stdio.h>
int main()
{
    long long int count, b, p, m, ans, x, y, z;
    while(scanf("%lld %lld %lld", &b, &p, &m) == 3)
    {
        if(b != 0 && p == 0)
        printf("1\n");
        else
        {
        ans = b % m;
        for(count = 2; count <= p && count <= 46340; ++count)
        {
            ans = (ans * (b % m)) % m;
        }
        z = ans;
        if(count - 1 < p)
        {
            x = p / 46340 - 1;
            y = p % 46340;
            for(count = 1; count <= x; ++count)
            ans = (ans * z) % m;
            for(count = 1; count <= y; ++count)
            ans = (ans * (b % m)) % m;
        }
        printf("%lld\n", ans);
        }
    }
    return 0;
}
