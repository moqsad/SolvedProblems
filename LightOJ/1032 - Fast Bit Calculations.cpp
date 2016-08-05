#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//long long func(long long n)
//{
//
//}

int main()
{
    long long t, cnt, n, ans, x, total;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);
        n += 1;
        total = 0;
        while(n > 0)
        {
            ans = 0;
            x = 1;
            while(x <= n)
            {
                ans = 2 * ans + x / 2;
                x *= 2;
            }
            x /= 2;
            ans = (ans - x / 2) / 2;
            total += ans;
            n -= x;
            if(n > x / 2)
                total += n - x / 2;
        }
        printf("Case %lld: %lld\n", cnt, total);
    }
    return 0;
}
