#include <bits/stdc++.h>
using namespace std;

int check[1005][1005], dp[1005][1005];
char arr[1005];

bool ispal(int s, int e)
{
    if(s >= e)
        return 1;

    if(check[s][e] != -1)
        return check[s][e];

    if(ispal(s + 1, e - 1) && arr[s] == arr[e])
        return check[s][e] = 1;
    return check[s][e] = 0;
}

int func(int s, int e)
{
    if(s > e)
        return 0;

    if(dp[s][e] != -1)
        return dp[s][e];

    if(ispal(s, e))
        return dp[s][e] = 0;

    if(arr[s] == arr[e])
        return dp[s][e] = func(s + 1, e - 1);
    return dp[s][e] = 1 + min(func(s + 1, e), func(s, e - 1));
}

void print(int s, int e)
{
    if(s < e)
    {
        if(arr[s] == arr[e])
        {
            printf("%c", arr[s]);
            print(s + 1, e - 1);
            printf("%c", arr[e]);
        }

        else if(dp[s][e - 1] < dp[s + 1][e])
        {
            printf("%c", arr[e]);
            print(s, e - 1);
            printf("%c", arr[e]);
        }
        else
        {
            printf("%c", arr[s]);
            print(s + 1, e);
            printf("%c", arr[s]);
        }
    }
    else if(s == e)
        printf("%c", arr[s]);
}

int main()
{
    while(scanf("%s", arr) == 1)
    {
        memset(check, -1, sizeof(check));
        memset(dp, -1, sizeof(dp));

        printf("%d ", func(0, strlen(arr) - 1));
        print(0, strlen(arr) - 1);
        printf("\n");
    }
    return 0;
}
