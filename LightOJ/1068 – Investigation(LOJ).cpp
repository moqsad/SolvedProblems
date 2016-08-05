#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int dp[12][100][100], a, b, k, n;

int func(int index, int mod, int nummod, int multi)
{
    if(index  == n)
    {
        if(mod == 0 && nummod == 0)
        {
            return 1;
        }
        else
            return 0;
    }

    int x = 0, i;

    if(dp[index][mod][nummod] != -1)
        return dp[index][mod][nummod];

    for(i = 0; i < 10; ++i)
    {
        x += func(index +  1, (i + mod) % k, ((nummod + i * multi) % k), multi / 10);
    }

    return dp[index][mod][nummod] = x;
}

int main()
{
    int t, cnt, x, i, j, ans, minus_, plus_, y, z, w;
    long long multi;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d", &a, &b, &k);
        if(k > 95)
            printf("Case %d: 0\n", cnt);

        else
        {
            memset(dp, -1, sizeof(dp));
            x = b;
            n = z = 0;
            multi = 1;
            while(x > 0)
            {
                z += x % 10;
                ++n;
                x /= 10;
                multi *= 10;
            }

            multi /= 10;
            --n;
            x = b / multi;

            minus_ = plus_ = ans = 0;

            for(i = 0; i < x; ++i)
            {
                ans += func(0, i % k, (i * multi) % k, multi / 10);
            }

            if(b % k == 0 && z % k == 0)
                plus_ += 1;

            y = n;
            z = x * multi;
            w = x;

            for(i = 0; i < y; ++i)
            {
                --n;
                multi /= 10;
                x = (b / multi) % 10;
                memset(dp, -1, sizeof(dp));
                for(j = 0; j < x; ++j)
                    plus_ += func(0, (w + j) % k, (z + j * multi) % k, multi / 10);
                z += x * multi;
                w += x;
            }

            x = a;
            n = 0;
            multi = 1;
            while(x > 0)
            {
                ++n;
                x /= 10;
                multi *= 10;
            }

            y = n;
            z = 0;
            w = 0;
            for(i = 0; i < y; ++i)
            {
                memset(dp, -1, sizeof(dp));
                --n;
                multi /= 10;
                x = (a / multi) % 10;
                memset(dp, -1, sizeof(dp));
                for(j = 0; j < x; ++j)
                    minus_ += func(0, (w + j) % k, (z + j * multi) % k, multi / 10);
                z += x * multi;
                w += x;
            }
            printf("Case %d: %d\n", cnt, ans + plus_ - minus_);
        }
    }
    return 0;
}

/*
10
1 25 2
1 1231223232 2
*/
