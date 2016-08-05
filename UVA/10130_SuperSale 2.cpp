#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int price[1010], weight[1010], dp[35], CAP, n;

int main()
{
    int t, cnt, i, g, sum, j;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%d %d", &price[i], &weight[i]);
        }
        memset (dp, 0, sizeof (dp));
        for (j = 0; j < n; j++)
        {
            for (i = 30; i > 0; --i)
            {
                if(weight[j] <= i && dp[i] < dp[i - weight[j]] + price[j])
                    dp [i] = dp [i - weight[j]] + price[j];
            }
        }
        scanf("%d", &g);
        sum = 0;
        for(i = 0; i < g; ++i)
        {
            scanf("%d", &CAP);
            sum += dp[CAP];
        }
        printf("%d\n", sum);
    }
    return 0;
}

