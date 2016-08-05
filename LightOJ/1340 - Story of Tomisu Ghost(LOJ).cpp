#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <iostream>
using namespace std;

#define mod 10000019
#define sz 50030

long long preans[100010];
bool arr[50030];
long long prime[50010];

long long bigmod(long long num, long long power)
{
    if(power == 0)
        return 1;

    long long ret = bigmod(num, power / 2);
    ret = (ret * ret) % mod;

    if(power % 2 == 1)
        ret = (ret * num) % mod;

    return ret;
}

void sieve()
{
    long long i, j, k, cnt = 0;

    prime[cnt++] = 2;

    for(i = 3; i < sz; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < sz; j += k)
                arr[j] = 1;
        }
    }
//    printf("%lld %lld__________\n", cnt, prime[cnt-1]);
}

int main()
{
    long long t, cnt, n, trailingzero, i, x, j, temp, tempans, ans;

    preans[1] = 1;

    for(i = 2; i <= 100000; ++i)
        preans[i] = (preans[i - 1] * i) % mod;

    sieve();

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &n, &trailingzero);

        if(trailingzero == 1)
            printf("Case %lld: %lld\n", cnt, preans[n]);
        else
        {
            ans = 1;
            x = n / 2;
            i = 0;
            j = 1;

            while(prime[i] <= x)
            {
                temp = prime[i];
                tempans = 0;
                while(n / temp > 0)
                {
                    tempans += n / temp;
                    temp *= prime[i];
                }
                ans = (ans * bigmod(prime[i], tempans / trailingzero)) % mod;
                ++i;
            }
            if(ans == 1)
                ans = -1;
            printf("Case %lld: %lld\n", cnt, ans);
        }
    }

    return 0;
}
