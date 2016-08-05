#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

map <long long, long long> mm;
long long fact[3][1010], arr[20];

int main()
{
    long long prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    long long x, t, i, j, k, a, b, p, y, cnt, n;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld %lld", &n, &a, &b);
        mm.clear();
        memset(fact, 0, sizeof(fact));
        i = 0;
        j = 0;
        x = sqrt(a) + 1;
        while(prime[i] < x)
        {
            if(a % prime[i] == 0)
            {
                mm[prime[i]] = 1;
                arr[j++] = prime[i];
                while(a % prime[i] == 0)
                {
                    ++fact[0][prime[i]];
                    a /= prime[i];
                }
            }
            ++i;
        }
        if(a > 1)
        {
            if(mm.find(a) == mm.end())
            {
                mm[a] = 1;
                arr[j++] = a;
            }
            ++fact[0][a];
        }
        i = 0;
        x = sqrt(b) + 1;
        while(prime[i] < x)
        {
            if(b % prime[i] == 0)
            {
                if(mm.find(prime[i]) == mm.end())
                    arr[j++] = prime[i];
                while(b % prime[i] == 0)
                {
                    ++fact[1][prime[i]];
                    b /= prime[i];
                }
            }
            ++i;
        }
        if(b > 1)
        {
            if(mm.find(b) == mm.end())
                arr[j++] = b;
            ++fact[1][b];
        }
        sort(arr, arr + j);
        for(k = 2; k <= n; ++k)
            for(i = 0; i < j; ++i)
            {
                fact[2][arr[i]] = fact[0][arr[i]] + fact[1][arr[i]];
                fact[0][arr[i]] = fact[1][arr[i]];
                fact[1][arr[i]] = fact[2][arr[i]];
            }
        for(i = 0; i < j; ++i)
            printf("%lld %lld\n", arr[i], fact[2][arr[i]]);
        printf("\n");
    }
    return 0;
}
