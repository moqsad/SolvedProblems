#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

char arr[60][60];
int m, n, p[] = {0, 0, -1, 1}, q[] = {-1, 1, 0, 0}, total;

void dfs(int row, int column)
{
    int i, x, y;
    for(i = 0; i < 4; ++i)
    {
        x = row + p[i];
        y = column + q[i];
        if(x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == 'T')
            return;
    }
    for(i = 0; i < 4; ++i)
    {
        x = row + p[i];
        y = column + q[i];
        if(x >= 0 && x < n && y >= 0 && y < m)
        {
            if(arr[x][y] != '#')
            {
                if(arr[x][y] == '.')
                {
                    arr[x][y] = '#';
                    dfs(x, y);
                }
                else
                {
                    arr[x][y] = '#';
                    ++total;
                    dfs(x, y);
                }
            }
        }
    }
    return ;
}

int main()
{
    int i, j, cnt, p;
    while(scanf("%d %d", &m, &n) == 2)
    {
        for(i = 0; i < n; ++i)
            scanf("%s", arr[i]);
        p = 0;
        total = 0;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < m; ++j)
            {
                if(arr[i][j] == 'P')
                {
                    arr[i][j] = '#';
                    dfs(i, j);
                    p = 1;
                    break;
                }
            }
            if(p == 1)
                break;
        }
        printf("%d\n", total);
    }
    return 0;
}
