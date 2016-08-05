#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define mod 1000000007

int f[2000010], fin[2000010];

long long bigmod(int data, int power)
{
    if(power == 0)
        return 1LL;

    long long x = bigmod(data, power / 2);

    x = (x * x) % mod;

    if(power % 2 == 1)
        x = (x * data) % mod;
    return x;
}

void fact(void)
{
    int i;
    long long x;
    f[0] = 1;
    for(i = 1; i <= 2000000; ++i)
    {
        x = ((long long)i * (long long)f[i - 1]) % mod;
        f[i] = (int)x;
    }
}

void factin(void)
{
    int i;
    long long x;
    fin[0] = bigmod(1, mod - 2);
    for(i = 1; i <= 2000000; ++i)
    {
        x = (bigmod(i, mod - 2) * (long long)fin[i - 1]) % mod;
        fin[i] = (int)x;
    }
}

int main()
{
    fact();
    factin();
//    printf("%d %d__________\n", f[2], f[2]);
    int t, cnt, n, k;
    long long x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &k);
        x = ((long long)f[n + k - 1] * (long long)fin[k - 1]);
        printf("Case %d: %lld\n", cnt, ((x % mod) * (long long)fin[n]) % mod);
    }
    return 0;
}
