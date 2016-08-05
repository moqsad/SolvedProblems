#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
using namespace std;

int num[30], dp[30][300], total, n;
char arr[200];

int func(int i, int weight)
{
    if(i == n)
        return 0;
    if(dp[i][weight] != -1)
        return dp[i][weight];
    int profit1 = 0, profit2;
    if(num[i] + weight <= total)
        profit1 = num[i] + func(i + 1, num[i] + weight);
    profit2 = func(i + 1, weight);
    return dp[i][weight] = max(profit1, profit2);
}

int main()
{
    int t, y, cnt, i, sum;
    scanf("%d\n", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        gets(arr);
        stringstream sin (arr);

        i = 0;
        sum = 0;
        while(sin >> num[i])
        {
            sum += num[i];
            ++i;
        }

        n = i;
        if(sum % 2 == 1)
            printf("NO\n");
        else
        {
            total = sum / 2;
            memset(dp, -1, sizeof(dp));
            y = func(0, 0);
            if(y == total)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
