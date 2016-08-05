#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct data
{
    int a, b, define;
};

int arr[110], n;

data dp[110][110][3];

data func(int start, int finish, int jenibe)
{
    data info, info2;

    if(start > finish)
    {
        info.a = 0;
        info.b = 0;
        info.define = 1;
        return info;
    }

    if(dp[start][finish][jenibe].define != -1)
        return dp[start][finish][jenibe];

    int i, sum = 0, sum2 = 0, end_ = finish, x, max_ = -2000000000;

    if(jenibe == 1)
        x = 2;
    else
        x = 1;

    if(jenibe == 1)
    {
        for(i = start; i <= finish; ++i)
        {
            sum += arr[i];
            sum2 += arr[end_--];
            info = func(i + 1,  finish, x);
            if(max_ < info.a + sum)
            {
                info2 = info;
                max_ = info2.a = sum + info.a;
            }
            info = func(start, end_, x);
            if(max_ < info.a + sum2)
            {
                info2 = info;
                max_ = info2.a = sum2 + info.a;
            }
        }
    }


    else
    {
        for(i = start; i <= finish; ++i)
        {
            sum += arr[i];
            sum2 += arr[end_--];

            info = func(i + 1,  finish, x);
            if(max_ < info.b + sum)
            {
                info2 = info;
                max_ =   info2.b = sum + info.b;
            }

            info = func(start, end_, x);
            if(max_ < info.b + sum2)
            {
                info2 =info;
                max_ = info2.b = sum2 + info.b;
            }
        }
    }

//    printf("%d %d ----> %d(a : %d & b : %d)\n", start, finish, jenibe, info2.a, info2.b);

    return dp[start][finish][jenibe] = info2;
}

int main()
{
    int t, cnt, sum, i, j;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        sum = 0;
        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }

        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
            {
                dp[i][j][1].define = -1;
                dp[i][j][2].define = -1;
            }

        info = func(1, n, 1);
//        printf("%d   %d__________\n", info.a, info.b);
        printf("Case %d: %d\n", cnt, 2 * info.a - sum);
    }
    return 0;
}

/*
6
1 2 3 -100 -10 7
--->83????
4
4 -10 -20 7
--->7????

3
2 -6 3
*/
