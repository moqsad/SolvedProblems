#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int p[110], w[110], dp[110][10010], n;

int func(int index, int weight)
{
    if(index == n)
        return 0;

    if(dp[index][weight] != -1)
        return dp[index][weight];

    int x, y = 0;

    x = func(index +1, weight);
    if(weight - w[index] >= 0)
    y = p[index] + max(func(index + 1, weight - w[index]), func(index, weight - w[index]));
    return dp[index][weight] = max(x, y);
}

int main()
{
    int t, cnt, num, sum, weight, i;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        sum = 0;
        scanf("%d %d", &n, &weight);
        for(i = 0; i < n; ++i)
        {
            scanf("%d %d %d", &p[i], &num, &w[i]);
            sum += num * w[i];
        }

        if(sum > weight)
            printf("Case %d: Impossible\n", cnt);
        else
        {
            memset(dp, -1, sizeof(dp));
            weight -= sum;
            printf("Case %d: %d\n", cnt, func(0, weight));
        }
    }
    return 0;
}
