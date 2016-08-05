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

bool arr[10000030];
long long prime[665010];

void sieve()
{
    long long i, j, k, cnt = 0;

    prime[cnt++] = 2;

    for(i = 3; i < 10000020; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 10000020; j += k)
                arr[j] = 1;
        }
    }

//    printf("%lld_______%lld\n", cnt, prime[cnt - 1]);
}

int main()
{
    long long t, cnt, i, x, y, n, ans;

    sieve();

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);

        x = sqrt(n) + 2;
        ans = 1;

        for(i = 0; prime[i] < x; ++i)
        {
            if(n % prime[i] == 0)
            {
                y = 1;
                while(n % prime[i] == 0)
                {
                    n /= prime[i];
                    ++y;
                }

                ans = (2 * ans - 1) * (y - 1) + ans;
            }
        }

        if(n > 1)
            ans = (2 * ans - 1) + ans;

        printf("Case %lld: %lld\n", cnt, ans);
    }

    return 0;
}
