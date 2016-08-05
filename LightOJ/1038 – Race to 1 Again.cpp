#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

double dp[100010];

double func(int n)
{
    if(n == 1)
        return 1;

    if(dp[n] != 0)
        return dp[n];

    x = sqrt(n);

}

int main()
{
    int t, cnt;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        printf("Case %d: %.8lf\n", cnt, func(n));
    }
    return 0;
}
