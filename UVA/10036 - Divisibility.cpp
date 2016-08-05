#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int arr[10002], dp[10002][102], k, n, p, x;

void func(int index, int mod)
{
    if(index == n)
    {
        if(mod == 0)
        {
            p = 1;
        }
        return ;
    }

    int y;
    if(mod > 0)
        y = mod;
    else
        y = - mod;

    if(dp[index][y] == x)
        return ;

    func(index + 1, (mod + arr[index]) % k);

    if(p == 1)
        return ;

    func(index + 1, (mod - arr[index]) % k);
    dp[index][y] = x;
}

int main()
{
    int cnt, t, i;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &k);
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        p = 0;
        ++x;
        func(1, arr[0] % k);
        if(p == 1)
            printf("Divisible\n");
        else
            printf("Not divisible\n");
    }
    return 0;
}
