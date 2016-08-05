#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

int n, p, x, target, j, arr[105], dp[105][64010];
char ans[105];

void func(int index, int hoice)
{
    if(index == n)
    {
        if(hoice == target)
            p = 1;
        return;
    }

    if(dp[index][hoice + 32000] == x)
        return;

    if(hoice + arr[index] <= 32000)
    {
        func(index + 1, hoice + arr[index]);
        if(p == 1)
        {
            ans[--j] = '+';
            return ;
        }
    }

    if(hoice - arr[index] >= -32000)
    {
        func(index + 1, hoice - arr[index]);
        if(p == 1)
        {
            ans[--j] = '-';
            return ;
        }
    }

    if(abs(hoice * arr[index]) <=32000)
    {
        func(index + 1, hoice * arr[index]);
        if(p == 1)
        {
            ans[--j] = '*';
            return ;
        }
    }

    if(hoice % arr[index] == 0)
    {
        func(index + 1, hoice / arr[index]);
        if(p == 1)
        {
            ans[--j] = '/';
            return ;
        }
    }

    dp[index][hoice + 32000] = x;
}

int main()
{
    int t, cnt, i;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        scanf("%d", &target);
        ++x;
        j = n;
        p = 0;
        func(1, arr[0]);
        if(p == 1)
        {
            printf("%d", arr[0]);
            for(i = 1; i < n; ++i)
                printf("%c%d", ans[i], arr[i]);
            printf("=%d\n", target);
        }
        else
            printf("NO EXPRESSION\n");
    }
    return 0;
}
