#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct data
{
    int value, color;
    string s;
};

int n, m, arr[12][102];
data dp[12][102];
char arr2[3];

data func(int r, int c)
{
    data info, info2, info3, min_;

    if(c == m)
    {
        info.value = 0;
        info.color = 0;
        info.s = "";
        return dp[r][c] = info;
    }

    if(dp[r][c].color != -1)
        return dp[r][c];


    int x, y;
    x = r + 1;
    y = r - 1;
    if(x  == n)
        x = 0;
    if(y < 0)
        y = n - 1;

    info2 = func(x, c + 1);
    info3 = func(y, c + 1);

    if(info2.value < info3.value)
        min_ = info2;
    else if(info2.value > info3.value)
        min_ = info3;
    else
    {
        if(info2.s < info3.s)
            min_ = info2;
        else
            min_ = info3;
    }

    info = func(r, c + 1);

    if(min_.value > info.value)
        min_ = info;
    else if(min_.value == info.value)
    {
        if(min_.s > info.s)
            min_ = info;
    }

    min_.value = min_.value +  arr[r][c];
    arr2[0] = r + 1;
    min_.s = arr2 + min_.s;
//    printf("%d %d %d..........\n", r, c, min_.value);
        return dp[r][c] = min_;
}

int main()
{
    int i, j;
    arr2[1] = '\0';
    data info, min_;
    while(scanf("%d %d", &n, &m) == 2)
    {
        for(i = 0; i < n; ++i)
            for(j = 0; j < m; ++j)
            {
                scanf("%d", &arr[i][j]);
                dp[i][j].color = -1;
            }

        min_.value = 1000000000;
        min_.color = 0;
        for(i = 0; i < n; ++i)
        {
            info = func(i, 0);
            if(min_.value > info.value)
                min_ = info;
        }
        printf("%d", min_.s[0]);
        for(i = 1; i < m; ++i)
            printf(" %d", min_.s[i]);
        printf("\n%d\n", min_.value);
    }
    return 0;
}

/*
2 3
12 34 2
23 3 433
*/
