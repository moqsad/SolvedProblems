#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
double arr[110], dp[110];

double func(int index)
{
    if(index  == n)
        return arr[n];

    if(index > n)
        return -1;

    if(dp[index] != -1)
        return dp[index];

    int  i;
    double x, sum = 0, cnt = 0;
    for(i = 1; i <= 6; ++i)
    {
        x = func(index + i);
        if(x != -1)
        {
            cnt += 1;
            sum += x;
        }
    }
    dp[index] = arr[index] + (sum) / cnt;
    return dp[index];
}

int main()
{
    int cnt, t, i;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
        {
            scanf("%lf", &arr[i]);
            dp[i] = -1;
        }

        printf("Case %d: %.8lf\n", cnt, func(1));
    }
    return 0;
}
