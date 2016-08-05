#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

bool arr[1000005];
long long prime[80000], cnt;

// there will be a blank line after each test case

void sieve(void)
{
    long long i, j, k;

    prime[cnt++] = 2;

    for(i = 3; i < 1000005; i += 2)
    {
        if(!arr[i])
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 1000005; j += k)
                arr[j] = 1;
        }
    }
}

int main()
{
    sieve();
    long long n, i, p = 0;
    while(scanf("%lld", &n) == 1 && n >= 0)
    {
        i = 0;
        while(i < cnt)
        {
            if(n % prime[i] == 0)
            {
                while(n % prime[i] == 0)
                {
                    n /= prime[i];
                    printf("    %lld\n", prime[i]);
                }
            }
            ++i;
        }
        if(n > 1)
            printf("    %lld\n", n);

        printf("\n");
    }
    return 0;
}
