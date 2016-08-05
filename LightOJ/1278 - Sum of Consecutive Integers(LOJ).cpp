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

#define sz 10000020

bool arr[sz];
long long prime[665000];

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
}

int main()
{
    sieve();

    long long t, cnt, sum, i;
    long long N, x, total;

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &N);

        x = sqrt(N) + 2;
        total = 1;

        for(i = 0; prime[i] < x; ++i)
        {
            if(N % prime[i] == 0)
            {
                sum = 0;
                while(N % prime[i] == 0)
                {
                    N /= prime[i];
                    ++sum;
                }
                if(i > 0)
                    total *= (sum + 1);
            }
        }

        if(N > 1)
            total *= 2;

        printf("Case %lld: %lld\n", cnt, total - 1);
    }

    return 0;
}
