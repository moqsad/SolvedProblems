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

#define sz 1000020

bool arr[sz];
int prime[78510];

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
    int t, cnt;
    long long b, a, a2, ans, x, y, i;

    sieve();

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &a, &b);

        if(b > sqrt(a))
        {
            printf("Case %d: 0\n", cnt);
            continue ;
        }

        a2 = a;
        ans = 1;
        x = sqrt(a) + 2;

        i = 0;
        while(prime[i] < x)
        {
            if(a % prime[i] == 0)
            {
                y = 1;
                while(a % prime[i] == 0)
                {
                    a /= prime[i];
                    ++y;
                }
                ans *= y;
                x = sqrt(a) + 2;
            }
            ++i;
        }

        if(a > 1)
            ans *= 2;

        ans /= 2;

        for(i = 1; i < b; ++i)
            if(a2 % i == 0)
                --ans;

//        if(ans % 2 == 1 && sqrt(a2) * sqrt(a2) != a2) // karon bijor howa manei sobgul prime jor sonkhok ace, tai ei khetre square somvob....
//            ans = ans / 2 + 1;
//        else

        printf("Case %d: %lld\n", cnt, ans);
    }

    return 0;
}
