#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

struct data
{
    int arr[12];
};

data dp[10][2][2];
int arr2[12], temp[12], n;

data func(int index, int flag, int pre)
{
    data ans, info;
    int i, j, lim, nflag;

    for(i = 0; i <= 10; ++i)
        ans.arr[i] = 0;

    if(index == n)
    {
        ans.arr[10] = 1;
        return ans;
    }

    if(dp[index][flag][pre].arr[10] != -1)
        return dp[index][flag][pre];

    lim = (flag == 0) ? 9 : arr2[index];

    for(i = 0; i <= lim; ++i)
    {
        if(flag == 1 && i == lim)
            nflag = 1;
        else
            nflag = 0;

        if(i > 0 || pre == 1)
            info = func(index + 1, nflag, 1);
        else
            info = func(index + 1, nflag, 0);

        for(j = 0; j <= 10; ++j)
            ans.arr[j] += info.arr[j];

        if(i > 0 || pre == 1)
            ans.arr[i] += info.arr[10];
    }
    return dp[index][flag][pre] = ans;
}

int main()
{
    int a, b, i, j, k;
    data info, info2;
    while(scanf("%d %d", &a, &b) == 2)
    {
        if(a == 0 && b == 0)
            break ;
        --a;
        n = 0;
        while(a > 0)
        {
            temp[n++] = a % 10;
            a /= 10;
        }

        j = n - 1;
        for(i = 0; i < n; ++i)
            arr2[i] = temp[j--];

        for(i = 0; i <= n; ++i)
            dp[i][1][0].arr[10] = dp[i][1][1].arr[10] = dp[i][0][0].arr[10] = dp[i][0][1].arr[10] = -1;

        info = func(0, 1, 0);

        n = 0;
        while(b > 0)
        {
            temp[n++] = b % 10;
            b /= 10;
        }

        j = n - 1;
        for(i = 0; i < n; ++i)
            arr2[i] = temp[j--];

        for(i = 0; i <= n; ++i)
            dp[i][1][0].arr[10] = dp[i][1][1].arr[10] = dp[i][0][0].arr[10] = dp[i][0][1].arr[10] = -1;

        info2 = func(0, 1, 0);

        printf("%d", info2.arr[0] - info.arr[0]);
        for(i = 1; i < 10; ++i)
            printf(" %d", info2.arr[i] - info.arr[i]);
        printf("\n");
    }
    return 0;
}
