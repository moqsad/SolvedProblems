#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

#define inf 1000000000

int num[20], dp[16][66000], n;
char arr[20][20];

int func(int start, int depth)
{
    if(depth == n)
        return 0;

    if(dp[depth][start] != -1)
        return dp[depth][start];

    int min_ = inf, min2_, x, i, j;
    for(i = 0; i < n; ++i)
    {
        if(((1 << i) & start) == 0)
        {
            min2_ = num[i];
            for(j = 0; j < n; ++j)
            {
                if(arr[j][i] != '0' && ((1 << j) & start))
                {
                    x = num[i] / (arr[j][i] - 48);

                    if(num[i] % (arr[j][i] - 48) != 0)
                        ++x;

                    if(x < min2_)
                        min2_ = x;
                }
            }
            min_ = min(min_, min2_ + func((1 << i) | start, depth + 1));
        }
    }

    return dp[depth][start] = min_;
}

int main()
{
    int t, cnt, i;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
            scanf("%d", &num[i]);

        for(i = 0; i < n; ++i)
            scanf("%s", arr[i]);

        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", cnt, func(0, 0));
    }
    return 0;
}
