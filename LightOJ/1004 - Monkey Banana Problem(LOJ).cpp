#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector <int> edge[205];
int n, m, dp[210][110];

int func(int i, int pos)
{
    if(i == n)
        return 0;
    if(dp[i][pos] != -1)
        return dp[i][pos];
    int  v1, v2;
    v1 = v2 = edge[i][pos];

    if(i < m)
    {
        v1 = v1 + func(i + 1, pos);
        v2 = v2 + func(i + 1, pos + 1);
    }

    else
    {
        if(pos - 1 >= 0)
        v1 = v1 + func(i + 1, pos - 1);
        if(pos < edge[i + 1].size())
        v2 = v2 + func(i + 1, pos);
    }
    return dp[i][pos] = max(v1, v2);
}

int main()
{
    int i, j, k, cnt, t, a;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
        {
            for(j = 1; j <= i; ++j)
            {
                scanf("%d", &a);
                edge[i].push_back(a);
            }
        }

        k = m = n;
        n = n + n;
        for(; i < n; ++i)
        {
            for(j = 1; j < k; ++j)
            {
                scanf("%d", &a);
                edge[i].push_back(a);
            }
            --k;
        }
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", cnt, func(1, 0));
        for(i = 1; i < n; ++i)
            edge[i].clear();
    }
    return 0;
}
