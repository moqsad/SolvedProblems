#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool arr[1000010];

long long prime[80000];

void sieve(void)
{
    long long i, j, k, cnt = 0;
    prime[cnt++] = 2;
    for(i = 3; i < 1000010; i += 2)
    {
        if(!arr[i])
        {
            arr[i] = 1;
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i;  j < 1000010; j += k)
                arr[j] = 1;
        }
    }
//    printf("%lld________________\n", cnt);
}

long long divide(long long data, long long by)
{
    long long ans = 1;
    while(data % by == 0)
    {
        ans *= by;
        data /= by;
    }
    return ans;
}

int main()
{
    sieve();
    long long t, cnt, a, b, c, L, x, i, p, q, r, yes;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        yes = 1;
        scanf("%lld %lld %lld", &a, &b, &L);
        x = sqrt(L) + 2;
        i = 0;
        c = 1;
        while(prime[i] < x)
        {
            if(L % prime[i] == 0)
            {
                p = divide(L, prime[i]);
                q = divide(a, prime[i]);
                r = divide(b, prime[i]);
                if(q > p || r > p)
                {
                    yes = 0;
                    break;
                }
                if(p > q && p > r)
                    c *= p;
                L /= p;
                a /= q;
                b /= r;
            }
            ++i;
        }

        if(L > 1)
        {
            q = divide(a, L);
            r = divide(b, L);
            if(q > L || r > L)
            {
                yes = 0;
            }
            if(L > q && L > r)
                c *= p;
            a /= q;
            b /= r;
        }

        if(a == 1 && b == 1 && yes)
            printf("Case %lld: %lld\n",cnt, c);
        else
            printf("Case %lld: impossible\n", cnt);
    }
    return 0;
}

/*
4
3 5 30
209475 6992 77086800
2 6 10
2 2 8
*/
