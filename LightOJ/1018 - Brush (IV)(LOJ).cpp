#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

struct data
{
    int x, y;
} arr[18];

int pos[18][18];

int dp[65537], z, n;

int func(int nici)
{
    if(nici == z - 1)
        return 0;

    if(dp[nici] != -1)
        return dp[nici];

    int ret = 20, i, j, temp;

    if(__builtin_popcount(nici) >= n - 2)
        return dp[nici] = 1;

    for(i = 1; i <= n; ++i)
    {
        if((nici & (1 << (i - 1))) == 0)
            break;
    }

    temp = nici | (1 << (i - 1));

    for(j = 1; j <= n; ++j)
        if((i != j) && (temp & (1 << (j - 1))) == 0)
        {
            ret = min(ret, 1 + func(nici | pos[i][j]));
            temp = temp | pos[i][j];
        }

    return dp[nici] = ret;
}

int main()
{
    int t, cnt, i, j, k, x, y, num;

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        for(i = 1; i <= n; ++i)
            scanf("%d %d", &arr[i].x, &arr[i].y);

        z = 1;
        for(i = 1; i <= n; ++i)
        {
            z *= 2;
            for(j = 1; j <= n; ++j)
            {
                if(j == i)
                    continue;

                y = arr[i].y - arr[j].y;
                x = arr[i].x - arr[j].x;
                num = 0;
                for(k = 1; k <= n; ++k)
                {
                    if((arr[k].y - arr[i].y) * x == y * (arr[k].x - arr[i].x))
                        num = num | (1 << k - 1);
                }
                pos[i][j] = num;
            }
        }

        for(j = 0; j < z; ++j)
            dp[j] = -1;

        printf("Case %d: %d\n", cnt, func(0));
    }
    return 0;
}
