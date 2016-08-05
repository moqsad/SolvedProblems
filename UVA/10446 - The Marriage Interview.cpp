#include <cstdio>
#include <iostream>
#include <cstring>
#include  <algorithm>
using namespace std;

unsigned long long dp[65][65];

unsigned long long func(int n, int back_)
{
//    printf("%d %d\n", n, back_);
    if(n <= 1)
        return 1;
//    printf("_________\n");

    if(dp[n][back_] != 0)
        return dp[n][back_];

   unsigned long long i, sum = 1;
    for(i = 1; i <= back_; ++i)
        sum += func(n - i, back_);

    return dp[n][back_] = sum;
}

int main()
{
    int n, back_, cnt = 0;
//    memset(dp, -1, sizeof(dp));
    while(scanf("%d %d", &n, &back_) == 2)
    {
        if(n > 60)
            break;

        printf("Case %d: %llu\n", ++cnt, func(n, back_)) ;
    }
    return 0;
}
