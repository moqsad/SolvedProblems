#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

long long prime[100005];
char arr[360];

void sieve()
{
    long long i, j, k;

    for(i = 2 * 2; i <= 100000; i += 2)
        prime[i] = 1;

    for(i = 3; i < 100000; i += 2)
    {
        if(prime[i] == 0)
        {
            k = 2 * i;
            for(j = i * i; j < 100000; j += k)
                prime[j] = 1;
        }
    }
}

int main()
{
    sieve();
    long long num, i, j, x, max_;
    while(scanf("%s", arr) == 1)
    {
        if(strlen(arr) == 1 && arr[0] == '0')
            break;

        max_ = 0;
        x = strlen(arr);
        for(i = 0; i < x; ++i)
        {
            num = 0;
            for(j = 0; j < 5 && i + j < x; ++j)
            {
                num = num * 10 + arr[i + j] - 48;
                if(prime[num] == 0)
                    max_ = max(max_, num);
            }
        }
        printf("%lld\n", max_);
    }
    return 0;
}
/*
11245
91321150448
1226406
0
*/
