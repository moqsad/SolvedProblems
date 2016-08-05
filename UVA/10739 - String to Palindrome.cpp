#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int dp[1010][1010];

char arr[1010];

int func(int start, int finish)
{
    if(start >= finish)
        return 0;

    if(dp[start][finish] != -1)
        return dp[start][finish];

    if(arr[start] == arr[finish])
        return dp[start][finish] = func(start + 1, finish - 1);
    else
        return dp[start][finish]=1+min(min(func(start+1,finish),func(start,finish-1)),func(start+1,finish-1));
}

int main()
{
    int t, cnt;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s", &arr);
        memset(dp, -1, sizeof(dp));
        printf("Case %d: %d\n", cnt, func(0, strlen(arr) - 1));
    }
    return 0;
}
