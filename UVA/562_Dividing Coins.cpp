#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int n, diff, total;
int dp[110][50010];
int cost[110];

void func(int i, int w)
{
    if(i == n)
        return;
    if(dp[i][w] != 0)
        return;
    int profit, x, y;

    profit = w + cost[i];

    x = total - profit;
    y = profit - x;
    if(y < 0)
        y = - y;
    if(y < diff)
        diff = y;

    dp[i][profit] = 1;
    dp[i][w] = 1;
    func(i + 1, profit);
    func(i + 1, w);

    return;
}

int main()
{
    int t, cnt, i;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d", &n);
        memset(dp, 0, sizeof(dp));
        total = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &cost[i]);
            total += cost[i];
        }
        diff = total;
        func(0, 0);
        printf("%d\n", diff);
    }
    return 0;
}
