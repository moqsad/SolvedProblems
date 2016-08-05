#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

/*ACCEPTED*/

int mixed, bad, n, num[55], dp[55][5][5][7][4];
char  arr[55];

void func(int index, int pre, int v, int con, int dif)
{
    if(v == 3 || con == 5)
    {
        if(dif == 0)
            bad = 1;
        else
            mixed = 1;
        return ;
    }

    if(index == n)
        return;

    if(dp[index][pre][v][con][dif] != -1)
    {
//        printf("_________________%d___%d\n", dp[index][pre][v][con][dif]);
        return ;
    }

    if(num[index] == 0)
    {
        if(pre == 0)
            func(index + 1, num[index], v + 1, 0, dif);

        else
            func(index + 1, num[index], 1, 0, 0);
    }

    else if(num[index] == 2)
    {
        if(pre == 2)
            func(index + 1, num[index], 0, con + 1, dif);

        else
            func(index + 1, num[index], 0, 1, 0);
    }

    else
    {
        if(pre == 0)
        {
            func(index + 1, 0, v + 1, 0, 1);
            if(v == 2 && dif == 0)
                func(index + 1, 2, 0, 1, 0);
            else
                func(index + 1, 2, 0, 1, 1);
        }

        else
        {
            func(index + 1, 2, 0, con + 1, 1);
            if(con == 4 && dif == 0)
                func(index + 1, 0, 1, 0, 0);
            else
                func(index + 1, 0, 1, 0, 1);
        }
    }

    dp[index][pre][v][con][dif] = 1;
}

int main()
{
    int t, cnt, i;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s", arr);
        n = strlen(arr);

        for(i = 0; i < n; ++i)
        {
            if(arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U')
                num[i] = 0;
            else if(arr[i] == '?')
                num[i] = 1;
            else
                num[i] = 2;
        }

        memset(dp, -1, sizeof(dp));
//        printf("%d___%d____\n", dp[1][1][1][1][1], dp[2][2][2][2][2]);

        mixed = bad = 0;
        func(0, 3, 0, 0, 0);
        if(bad == 1)
            printf("Case %d: BAD\n", cnt);
        else if(mixed == 1)
            printf("Case %d: MIXED\n", cnt);
        else
            printf("Case %d: GOOD\n", cnt);
    }
    return 0;
}
