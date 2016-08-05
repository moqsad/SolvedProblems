#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int x, y, n, dp[32][32], com;
char a[32], b[32];

long long dp2[62][32][32];

int lcs(int a1, int b1)
{
    if(a1 == x || b1 == y)
        return 0;

    if(dp[a1][b1] != -1)
        return dp[a1][b1];

    if(a[a1] == b[b1])
        return dp[a1][b1] = 1 + lcs(a1 + 1, b1 + 1);
    else
        return dp[a1][b1] = max(lcs(a1, b1 + 1), lcs(a1 + 1, b1));
}

long long func(int index, int a1, int b1, int common)
{
//    printf("%d %d %d_____\n", index, a1, b1);
    if(a1 == x)
    {
        if(common == com)
            return 1;
        else
            return 0;
    }

    else if(b1 == y)
    {
        if(common == com)
            return 1;
        else
            return 0;
    }

    if(dp2[index][a1][b1] != -1)
        return dp2[index][a1][b1];

    if(a[a1] == b[b1])
        return dp2[index][a1][b1] = func(index + 1, a1 + 1, b1 + 1, common + 1);
    else
        return dp2[index][a1][b1] = func(index + 1, a1 + 1, b1, common) + func(index + 1, a1, b1 + 1, common);
}

int main()
{
    int t, cnt;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s %s", a, b);
        x = strlen(a);
        y = strlen(b);
        memset(dp, -1, sizeof(dp));
        com = n = lcs(0, 0);
        n = x + y - n;
        memset(dp2, -1, sizeof(dp2));
        printf("Case %d: %d %lld\n", cnt, n, func(0, 0, 0, 0));
    }
    return 0;
}
