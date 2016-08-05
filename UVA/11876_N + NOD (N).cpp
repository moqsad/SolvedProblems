#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

long long prime[80000], arr[1000010], ans[70000];
long long func(long long x)
{
    long long beg, endd, mid;
    beg = 0;
    endd = 64725;
    while(beg < endd)
    {
        mid = (beg + endd) / 2;
        if(ans[mid] == x)
            return mid;
        if(ans[mid] < x)
            beg = mid + 1;
        else
            endd = mid - 1;
    }
    return beg;
}

int main()
{
    long long cnt = 0, i, j, k, x, y, r, s, t, m, n;

    prime[cnt++] = 2;
    arr[2] = 5;
    for(i = 3; i < 1000005; i += 2)
    {
        if(arr[i] == 0 )
        {
            prime[cnt++] = i;
            arr[i] = 5;
            k = i + i;
            for(j = i * i; j < 1000005; j += k)
            {
                arr[j] = 1;
            }
        }
    }
    j = 1;
    ans[0] = 1;
    ans[1] = 2;
    while(ans[j] < 1000005)
    {
        x = ans[j];
        if(arr[x] == 5)
        {
            ans[++j] = x + 2;
        }
        else
        {
            k = 0;
            y = x;
            r = 1;
            s = 1;
            while(arr[y] != 5 && y != 1)
            {
                if(y % prime[k] == 0)
                {
                    ++s;
                    y /= prime[k];
                    while(y % prime[k] == 0)
                    {
                        ++s;
                        y /= prime[k];
                    }
                }
                r *= s;
                s = 1;
                ++k;
            }
            if(y > 1)
                r *= 2;
            ans[++j] = x + r;
        }
//        if(j < 100)
//        printf("%lld\n", ans[j]);
    }
//    printf("%lld", j);
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &m, &n);
        x = func(m);
        x = x - 1;
        if(x < 0)
            x = 0;
        while(ans[x] < m)
            ++x;
        y = func(n);
        y += 1;
        if(y > 64725)
            y = 64725;
        while(ans[y] > n)
            --y;
        printf("Case %lld: %lld\n", cnt, y - x + 1);
    }
    return 0;
}

