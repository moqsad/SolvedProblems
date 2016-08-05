#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int arr[35], n, total, dp[35][650][650], sum;

void func(int i, int first, int second)
{
    int x, y;

    int third = sum - first - second;
    x = (first >= second && first >= third) ? first : (second >= first && second >= third) ? second : third;
    y = (first <= second && first <= third) ? first : (second <= first && second <= third) ? second : third;

    if(x - y < total)
        total = x - y;

    if(i == n)
        return ;

    if(dp[i][first][second] != 0 || dp[i][second][first] != 0)
        return ;

    func(i + 1, first + arr[i], second);
    dp[i + 1][first + arr[i]][second] = 1;
    func(i + 1, first, second + arr[i]);
    dp[i + 1][first][second + arr[i]] = 1;
    func(i + 1, first, second);
    dp[i + 1][first][second] = 1;
}

int main()
{
    int t, cnt, i, j, k;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        sum = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
//        memset(dp, 0, sizeof(dp));
        for(i = 0; i < n; ++i)
            for(j = 0; j <= sum; ++j)
            for(k = 0; k <= sum; ++k)
            dp[i][j][k] = 0;
        total = 1000000000;
        func(0, 0, 0);
        printf("Case %d: %d\n", cnt, total);
    }
    return 0;
}

/*
5
32
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
16
12
14
2
3
17
20
5
17
13
2
14
4
*/

