#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int dp[1002][1002], value[1002], finish2;
char arr[1002];

int palindrome_kina(int start, int finish)
{
    if(finish == start || finish - start == 1)
    {
        if(arr[start] == arr[finish])
            return 1;
        else
            return 0;
    }

    if(dp[start][finish] != -1)
        return dp[start][finish];

    int x;
    if(arr[start] == arr[finish])
        return dp[start][finish] = palindrome_kina(start + 1, finish - 1);
    else
        return dp[start][finish] = 0;
}

int palindrome(int start)
{
    if(value[start] != -1)
        return value[start];

    int x, min_ = 200000, i;

    x = palindrome_kina(start, finish2);

    if(x == 1)
        return  value[start] = x;

    for(i = start; i < finish2; ++i)
    {
        x = palindrome_kina(start, i);
        if(x)
        {
            x += palindrome(i + 1);
            min_  = min(min_, x);
            if(min_ == 2)
                break;
        }
    }

    return value[start] = min_;
}

int main()
{
    int t, cnt, x, i, j;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s", arr);
        finish2 = strlen(arr);
        for(i = 0; i < finish2; ++i)
            for(j = i; j < finish2; ++j)
                dp[i][j] = -1;
        memset(value, -1,  sizeof(value));
        --finish2;
        printf("Case %d: %d\n", cnt, palindrome(0));
    }
    return 0;
}
