#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int price[1010], weight[1010], dp[1010][35], CAP, n;

int func(int i, int w)
{
    if(i == n)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    int profit1 = 0, profit2 = 0;
    if(w + weight[i] <= CAP)
        profit1 = price[i] + func(i + 1, w + weight[i]);
    profit2 = func(i, w);
    dp[i][w] = max(profit1, profit2);
    return dp[i][w];
}

int main()
{
    int t, cnt, i, g, sum;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%d %d", &price[i], &weight[i]);
        }
        scanf("%d", &g);
        sum = 0;
        for(i = 0; i < g; ++i)
        {
            scanf("%d", &CAP);
            memset(dp, -1, sizeof(dp));
            sum += func(0, 0);
        }
        printf("%d\n", sum);
    }
    return 0;
}
