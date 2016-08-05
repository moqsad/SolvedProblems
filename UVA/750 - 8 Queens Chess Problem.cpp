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
    int i, j, k = 0, cnt = 0, t, row, column;
    call(1);
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &row, &column);
        printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        for(i = 0; i < 92; ++i)
        {
            if(store[i][column] == row)
            {
                printf("%2d      %d %d %d %d %d %d %d %d\n", ++k, store[i][1], store[i][2], store[i][3],
                       store[i][4], store[i][5], store[i][6], store[i][7], store[i][8]); //probleme %2d bola cilo na....
            }
        }
        if(cnt < t)
            printf("\n");
        k = 0;
    }
    return 0;
}

