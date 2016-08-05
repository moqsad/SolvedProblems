#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int x, y, z, dp[52][52][52];
char a1[55], a2[55], a3[55];

int func(int a, int b, int c)
{
    if(a == x || b == y || c == z)
        return 0;
    if(dp[a][b][c] != -1)
        return dp[a][b][c];
    if(a1[a] == a2[b] && a1[a] == a3[c])
        return dp[a][b][c] = 1 + func(a + 1, b + 1, c + 1);
    else
        return  dp[a][b][c] = max(max(func(a, b + 1, c), func(a + 1, b, c)), func(a, b, c + 1));
}


int main()
{
    int cnt, t;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s %s %s", &a1, &a2, &a3);
        memset(dp, - 1, sizeof(dp));
        x = strlen(a1);
        y = strlen(a2);
        z = strlen(a3);
        printf("Case %d: %d\n", cnt, func(0, 0, 0));
    }
    return 0;
}
