#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int arr[20], ans[20], p, store[100][20], taken[20][20];

int color(int i, int j, int x)
{
    int k, l;
    for(k = i + 1; k < 9; ++k)
        taken[k][j] += x;

    k = i + 1;
    l = j + 1;
    while(k < 9 && l < 9)
    {
        taken[k][l] += x;
        ++k;
        ++l;
    }

    k = i + 1;
    l = j - 1;
    while(k < 9 && l > 0)
    {
        taken[k][l] += x;
        ++k;
        --l;
    }
}

void call(int i)
{
    int j, y;
    if(i == 9)
    {
        for(j = 1; j < 9; ++j)
            store[p][j] = ans[j];
        ++p;
        return;
    }
    for(j = 1; j < 9; ++j)
        if(taken[i][j] == 0)
        {
            ans[i] = j;
            color(i, j, 1);
            call(i + 1);
            color(i, j, -1);
        }
}

int main()
{
    int i, j, cnt = 0, t, sum, total;
    call(1);
    while(scanf("%d", &arr[1]) == 1)
    {
        for(i = 2; i < 9; ++i)
            scanf("%d", &arr[i]);
        total = 100;
        for(j = 0; j < 92; ++j)
        {
            sum = 0;
            for(i = 1; i < 9; ++i)
               {
                   if(arr[i] != store[j][i])
                    ++sum;
               }
               if(sum < total)
                total = sum;
        }
        printf("Case %d: %d\n", ++cnt, total);
    }
    return 0;
}
