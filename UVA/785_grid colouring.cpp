#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int p[] = {-1, 1, 0, 0}, q[] = {0, 0, -1, 1};
char arr[40][90], ch;

void dfs(int row, int column)
{
    int i, x, y;
    for(i = 0; i < 4; ++i)
    {
        x = row + p[i];
        y = column + q[i];
        if(arr[x][y] == ' ')
        {
            arr[x][y] = ch;
            //printf("%c**%d %d***\n", arr[x][y], x, y);
            dfs(x, y);
        }
    }
    return ;
}

int main()
{
    int i, j = 0, k, cnt, x, y;
    while(gets(arr[i]))
    {
        if(arr[i][0] == '_')
        {
            for(j = 0; j < i; ++j)
            {
                x = strlen(arr[j]);
                for(k = 0; k < x; ++k)
                {
                    if(arr[j][k] != ' ' && arr[j][k] != 'X')
                    {
                        ch = arr[j][k];
                        dfs(j, k);
                    }
                }
            }
            for(j = 0; j <= i; ++j)
                printf("%s\n", arr[j]);
            i = -1;
        }
        ++i;
    }
    return 0;
}
