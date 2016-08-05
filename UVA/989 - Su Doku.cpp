#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n, m, p, arr[15][15], taken[15][15], row[15][15], column[15][15], visit[15];

int testing(int i, int j, int k)
{
    int l, o, x, y, z;
    z = 1;
    x = i % m;
    if(x == 0)
        x = m;
    x = i - x + 1;
    y = j % m;
    if(y == 0)
        y = m;
    y = j - y + 1;
    for(l = x; l < m + x; ++l)
    {
        for(o = y; o < m + y; ++o)
        {
            if(!(l == i && o == j) && taken[l][o] == k)
            {
                z = 0;
                break;
            }
        }

        if(z == 0)
            break;
    }
    return z;
}

void backtrack(int i, int j)
{
    int k, l, o, z;

    if(j == n + 1)
    {
        ++i;
        j = 1;
    }

    if(i == n + 1)
    {
        for(l = 1; l <= n; ++l)
        {
            for(o = 1; o <= n; ++o)
                if(o == 1)
                    printf("%d", taken[l][o]);
                else
                    printf(" %d", taken[l][o]);
            printf("\n");
        }

        p = 1;
        return ;
    }

    if(arr[i][j] > 0)
    {
        z = testing(i, j, arr[i][j]);
        if(z == 1 && row[i][arr[i][j]] == 1 && column[arr[i][j]][j] == 1)
        {
            backtrack(i, j + 1);
        }
    }

    else
    {
        for(k = 1; k <= n; ++k)
        {
            z = testing(i, j, k);

            if(z == 1 && row[i][k] == 0 && column[k][j] == 0)
            {
                row[i][k] = 1;
                column[k][j] = 1;
                taken[i][j] = k;
                backtrack(i, j + 1);
                if(p == 1)
                    return ;
                taken[i][j] = 0;
                row[i][k] = 0;
                column[k][j] = 0;
            }
        }
    }
}

int main()
{
    int i, j, cnt = 0;
    while(scanf("%d", &m) == 1)
    {
        if(cnt > 0)
            printf("\n");

        n = m * m;

        p = 0;

        memset(arr, 0, sizeof(arr));
        memset(row, 0, sizeof(row));
        memset(column, 0, sizeof(column));

        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
            {
                scanf("%d", &arr[i][j]);
                taken[i][j] = arr[i][j];
                ++row[i][arr[i][j]];
                ++column[arr[i][j]][j];
            }

        backtrack(1, 1);

        if(p == 0)
            printf("NO SOLUTION\n");
        ++cnt;
    }
    return 0;
}

/*

3
0 6 0 1 0 4 0 5 0
0 0 8 3 0 5 6 0 0
2 0 0 0 0 0 0 0 1
8 0 0 4 0 7 0 0 6
0 0 6 0 0 0 3 0 0
7 0 0 9 0 1 0 0 4
5 0 0 0 0 0 0 0 2
0 0 7 2 0 6 9 0 0
0 4 0 5 0 8 0 7 0

3
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

2
2 3 0 0
0 0 0 0
1 0 0 0
0 0 0 0
*/
