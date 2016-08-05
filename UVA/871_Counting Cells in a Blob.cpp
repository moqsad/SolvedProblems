#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

int row, column, i, z, p[] = {0, -1, -1, -1, 0, 1, 1, 1}, q[] = {-1, -1, 0, 1, 1, 1, 0, -1};
char arr[30][30];

queue <int> Qrow;
queue <int> Qcolumn;

int BFS(void)
{
    while(!Qrow.empty())
    {
        Qrow.pop();
        Qcolumn.pop();
    }
    arr[row][column] = '0';
    Qrow.push(row);
    Qcolumn.push(column);

    int j, x, y, cnt = 1;
    while(!Qrow.empty())
    {
        row = Qrow.front();
        column = Qcolumn.front();

        Qrow.pop();
        Qcolumn.pop();

        for(j = 0; j < 8; ++j)
        {
            x = row + p[j];
            y = column + q[j];
            if(x >= 0 && x < i && y >= 0 && y < z && arr[x][y] == '1')
            {
                Qrow.push(x);
                Qcolumn.push(y);
                ++cnt;
                arr[x][y] = '0';
            }
        }
    }
    return cnt;

}

int main()
{
    int t, cnt, j, k, x, y;
    scanf("%d\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        i = 0;
        while(gets(arr[i]))
        {
            if(arr[i][0] == '\0')
                break;
            ++i;
        }
        x = 0;
        if(i > 0)
            z = strlen(arr[i - 1]);
        for(j = 0; j < i; ++j)
            for(k = 0; k < z; ++k)
            {
                if(arr[j][k] == '1')
                {
                    row = j;
                    column = k;
                    y = BFS();
                    if(x < y)
                        x = y;
                }
            }
        printf("%d\n", x);
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
