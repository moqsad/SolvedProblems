#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long f[1000010];

void fact(void)
{
    long long i;
    f[0] = 1;
    for(i = 1; i <= 1000000; ++i)
        f[i] = (i * f[i - 1]) % 1000003;
}

long long func(long long data, long long power)
{
    if(power == 1)
        return data;
    if(power == 0)
        return 0;

    long long mid = power / 2, ans;

    ans = func(data, mid);
    ans = (ans * func(data, mid)) % 1000003;

    if(power % 2 > 0)
        ans = (ans * data) % 1000003;

    return ans;
}

int main()
{
    long long t, cnt, n, k, ans, inv, inv2;
    fact();
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &n, &k);

//        printf("%lld________\n", f[n]);

        inv = func(f[k], 1000001);
        inv2 = func(f[n - k], 1000001);

//        printf("%lld++++++%lld\n", inv, inv2);
        ans = (f[n] * inv) % 1000003;
        ans = (ans * inv2) % 1000003;
        printf("Case %lld: %lld\n", cnt, ans);
    }
    return 0;
}
