#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int p[] = {0, 0, -1, 1}, q[] = {-1, 1, 0, 0};
char arr[35][90], ch;

void dfs(int row, int column)
{
    int i, x, y;
    for(i = 0; i < 4; ++i)
    {
        x = row + p[i];
        y = column + q[i];
        if(arr[x][y] == ' ')
        {
            arr[x][y] = '#';
            dfs(x, y);
        }
    }
    return;
}

int main()
{
    int n, cnt, i, j, k, x, p;
    scanf("%d\n", &n);
    for(cnt = 0; cnt < n; ++cnt)
    {
        i = 0;
        gets(arr[i]);
        while(arr[i][0] != '_')
        {
            gets(arr[++i]);
        }
        p = 0;
        for(j = 0; j <= i; ++j)
        {
            x = strlen(arr[j]);
            for(k = 0; k < x; ++k)
            {
                if(arr[j][k] == '*')
                {
                    arr[j][k] = '#';
                    p = 1;
                    dfs(j, k);
                    break;
                }
            }
            if(p == 1)
            break;
        }
        for(j = 0; j <= i; ++j)
            printf("%s\n", arr[j]);
    }
    return 0;
}
/*
1
jjjj
j  j
j* j
jjjj
_________
*/
