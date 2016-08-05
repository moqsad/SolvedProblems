#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int n, m, visit[105][105], dp[105][105], dp2[105][105];



int func(int r, int c)
{
    if(r == n && c == m)
    {
        return arr[r][c] + max(func2(r - 1, c), func2(r, c - 1));
    }

    if(dp[r][c] != -1)
        return dp[r][c];

    visit[r][c] = 1;

    int max_ = 0;

    if(r < n)
        max_ = func(r + 1, c) + arr[r][c];
    if(c < m)
        max_ = func(r, c + 1) + arr[r][c];

    visit[r][c] = 0;

    return dp[r][c] = max_;
}

int main()
{
    int t, cnt, i, j;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= m; ++j)
                scanf("%d", &arr[i][j]);

        memset(visit, 0, sizeof(visit));
        memset(dp, -1, sizeof(dp));
        memset(dp2, -1, sizeof(dp2));
        printf("Case %d: %d\n", cnt, func(1, 1));
    }
    return 0;
}
