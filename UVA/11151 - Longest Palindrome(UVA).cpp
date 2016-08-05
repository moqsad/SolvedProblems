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
        return dp[s][e] = e - s + 1;

    int max_, plus_ = 1;

    max_ = max(func(s, e - 1), func(s + 1, e));
    if(arr[s] == arr[e])
    {
        if(s != e)
            ++plus_;
        max_ = max(func(s + 1, e - 1) + plus_, max_);
    }
    return dp[s][e] = max_;
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
//        scanf("%s", arr);
        gets(arr);
        memset(check, -1, sizeof(check));
        memset(dp, -1, sizeof(dp));
        printf("%d\n", func(0, strlen(arr) - 1));
    }
    return 0;
}
//kjghkfuwweuibmbvnvfgjgu
//ghkg
