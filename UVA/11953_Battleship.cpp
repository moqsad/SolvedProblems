#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

int n, row, column, p[] = {0, -1, 0, 1}, q[] = {-1, 0, 1, 0};
char arr[110][110];

queue <int> Qrow;
queue <int> Qcolumn;

void BFS(void)
{
    Qrow.push(row);
    Qcolumn.push(column);

    int x, y, i;
    while(!Qrow.empty())
    {
        row = Qrow.front();
        column = Qcolumn.front();

        Qrow.pop();
        Qcolumn.pop();

        for(i = 0; i < 4; ++i)
        {
            x = row + p[i];
            y = column + q[i];
            if(x >= 0 && x < n && y >= 0 && y < n && (arr[x][y] == 'x' || arr[x][y] == '@'))
            {
                arr[x][y] = '.';
                Qrow.push(x);
                Qcolumn.push(y);
            }
        }
    }
    return ;
}

int main()
{
    int t, cnt, i, j, total;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        total = 0;
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
            scanf("%s", &arr[i]);
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
            {
                if(arr[i][j] == 'x')
                {
                    row = i;
                    column = j;
                    arr[i][j] = '.';
                    BFS();
                    ++total;
                }
            }
            printf("Case %d: %d\n", cnt, total);
    }
    return 0;
}

