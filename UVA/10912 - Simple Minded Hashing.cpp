#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int dp[28][28][355];

int func(int start, int l, int s)
{
    if(l == 0)
    {
        if(s == 0)
            return 1;
        else
            return 0;
    }

    if(s < start || start > 26)
        return 0;

    if(dp[start][l][s] != -1)
        return dp[start][l][s];

    int i, x;
    x = 0;
    for(i = start; i <= 26; ++i)
        x += func(i + 1, l - 1, s - i);
    return dp[start][l][s] = x;
}

int main()
{
    int cnt = 0, l, s;
    memset(dp, -1, sizeof(dp));
    while(scanf("%d %d", &l, &s) == 2)
    {
        if(l == 0 && s == 0)
            break;
        if(l > 26 || s > 351)
            printf("Case %d: 0\n",  ++cnt);
        else
            printf("Case %d: %d\n", ++cnt, func(1, l, s));
    }
    return 0;
}
