#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    long long t, cnt, n, ans;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);
        ans = 1;
        while(n % 2 == 0)
        {
            ans *= 2;
            n /= 2;
        }
        if(n != 1 && ans > 1)
            printf("Case %lld: %lld %lld\n", cnt, n, ans);
        else
            printf("Case %lld: Impossible\n", cnt);
    }
    return 0;
}
