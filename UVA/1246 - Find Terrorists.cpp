#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

long long prime[900000], arr[1000100], ans[1000100];

int main()
{
    long long cnt = 0, i, j, k, x, y, r, s, t, p, m, n;
    prime[cnt++] = 2;
    arr[2] = 5;
    ans[2] = 1;
    for(i = 3; i <= 1000100; ++i)
    {
        if(arr[i] == 0 && i % 2 == 1)
        {
            prime[cnt++] = i;
            arr[i] = 5;
            k = i + i;
            for(j = i * i; j < 1000100; j += k)
            {
                arr[j] = 1;
            }
        }
        if(arr[i] == 5)
        {
            ans[i] = 1;
        }
        else
        {
            y = i;
            j = 0;
            r = 1;
            s = 1;
            while(arr[y] != 5 && y != 1)
            {
                if(y % prime[j] == 0)
                {
                    ++s;
                    y /= prime[j];
                    while(y % prime[j] == 0)
                    {
                        ++s;
                        y /= prime[j];
                    }
                }
                r *= s;
                s = 1;
                ++j;
            }
            if(y > 1)
                r *= 2;
            if(arr[r] == 5)
                ans[i] = 1;
        }
    }
    scanf("%lld", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%lld %lld", &m, &n);
        p = 0;
        j = 0;
        for(i = m; i <= n; ++i)
        {
            if(ans[i] == 1)
            {
                ++j;
                p = 1;
                if(j == 1)
                    printf("%lld", i);
                else
                    printf(" %lld", i);
            }
        }
        if(p == 0)
            printf("-1");
        printf("\n");
    }
    return 0;
}
