#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long arr[20], num[20], dp[20][3][3], n;

void func(long long x)
{
    long long i = 0, j = 0;

    while(x > 0)
    {
        num[i++] = x % 10;
        x /= 10;
    }

    while(--i >= 0)
        arr[j++] = num[i];

    n = j;
}

long long solve(long long index, long long flag, long long pre)
{

    if(index == n)
        return 0;

    if(dp[index][flag][pre] != -1)
        return dp[index][flag][pre];

    long long ans = 0, x = 0, y, i = index + 1, lim, nflag, npre = pre;

    lim = (flag == 0) ? 9 : arr[index];

    if(pre == 1)
    {
        while(i < n)
        {
            if(flag == 1)
            {
                if(0 == lim)
                    y = arr[i];
                else
                    y = 9;
            }
            else
            y = 9;
            x = x * 10 + y;
            ++i;
        }
        ans += x + 1;
    }

    for(i = 0; i <= lim; ++i)
    {
        if(flag == 1 && i == lim)
            nflag = 1;
        else
            nflag = 0;
        if(npre  == 0 && i > 0)
            npre = 1;
        ans += solve(index + 1, nflag, npre);
    }


    return dp[index][flag][pre] = ans;
}

int main()
{
    long long t, cnt, a, b, x, y;
    scanf("%lld", &t);
    for(cnt  = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &a, &b);

        if(a - 1 >= 0)
        {
            func(a - 1);
            memset(dp, -1, sizeof(dp));
            x = solve(0, 1, 0) + 1;
        }
        else
            x = 0;

        func(b);
        memset(dp, -1, sizeof(dp));
        y = solve(0, 1, 0) + 1;
//        printf("%lld %lld_________\n", x, y);
        printf("Case %lld: %lld\n", cnt, y - x);
    }
    return 0;
}
