#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int taken[20][20], arr[20][20], total, ans[20];

int color(int i, int j, int x)
{
    int k, l;
    for(k = i + 1; k < 8; ++k)
        taken[k][j] += x;

    k = i + 1;
    l = j + 1;
    while(k < 8 && l < 8)
    {
        taken[k][l] += x;
        ++k;
        ++l;
    }

    k = i + 1;
    l = j - 1;
    while(k < 8 && l >= 0)
    {
        taken[k][l] += x;
        ++k;
        --l;
    }
}

void call(int i, int sum)
{
    int j, y;
    if(i == 8)
    {
//        for(j = 0; j < 8; ++j)
//            printf("%d______________\n", ans[j]);
//        printf("%d++++++++++++++\n", sum);
        if(sum > total)
            total = sum;
        return;
    }
    y = sum;
    for(j = 0; j <8; ++j)
        if(taken[i][j] == 0)
        {
            ans[i] = arr[i][j];
            sum += arr[i][j];
            color(i, j, 1);
            call(i + 1, sum);
            color(i, j, -1);
            sum = y;
        }
}

int main()
{
    int i, j, cnt, t;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        for(i = 0; i < 8; ++i)
            for(j = 0; j < 8; ++j)
                scanf("%d", &arr[i][j]);
        total = 0;
        call(0, 0);
        printf("%5d\n", total);
    }
    return 0;
}

