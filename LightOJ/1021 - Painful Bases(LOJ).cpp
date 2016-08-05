#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char arr[20];

long long dp[70000][20];

int base, k, ss;

long long func(int mod_, int color, int length)
{
    if(length == ss)
    {
        if(mod_ % k == 0)
            return 1;
        else
            return 0;
    }

    if(dp[color][mod_] != -1)
        return dp[color][mod_];

    int i, x, y;
    long long total = 0;

    for(i = 0; i < ss; ++i)
    {
        if(((1 << i) & color) == 0)
        {
            y = arr[i] - 48;
            if(arr[i] >= 'A' && arr[i] <= 'F')
                y = arr[i] - 55;
            x = (mod_ * base + y) % k;
            total += func(x, color | (1 << i), length + 1);
        }
    }
    return dp[color][mod_] = total;
}

int main()
{
    long long t, cnt;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &base, &k);
        memset(dp, -1, sizeof(dp));
        scanf("%s", arr);
        ss = strlen(arr);
        printf("Case %lld: %lld\n", cnt, func(0, 0, 0));
    }
    return 0;
}
