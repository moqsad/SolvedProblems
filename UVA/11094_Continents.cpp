#include <cstdio>
#include <cstring>
#include <cctype>
#include <queue>
#include <iostream>
using namespace std;

queue <int> Qrow;
queue <int> Qcolumn;
bool visit[30][30];

int m, n, row, column, p[] = {0, 0, -1, 1}, q[] = {-1, 1, 0, 0}, total;
char ch, ch2, arr[30][30];

void BFS(void)
{
    Qrow.push(row);
    Qcolumn.push(column);
    visit[row][column] = 1;
    int i, x, y;
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
            if(x >= 0 && x < m && y >= 0 && y < n && arr[x][y] == ch && visit[x][y] == 0)
            {
                ++total;
                arr[x][y] = ch2;
                visit[x][y] = 1;
                Qrow.push(x);
                Qcolumn.push(y);
            }
        }
        if(column == n - 1 && arr[row][0] == ch && visit[row][0] == 0)
        {
            ++total;
            arr[row][0] = ch2;
            visit[row][0] = 1;
            Qrow.push(row);
            Qcolumn.push(0);
        }
        if(column == 0 && arr[row][n - 1] == ch && visit[row][n - 1] == 0)
        {
            ++total;
            arr[row][n - 1] = ch2;
            visit[row][n - 1] = 1;
            Qrow.push(row);
            Qcolumn.push(n - 1);
        }
    }
    return ;
}

int main()
{
    int cnt, i, j, a, b, x;
    while(scanf("%d %d", &m, &n) == 2)
    {
        for(cnt = 0; cnt < m; ++cnt)
        {
            scanf("%s", arr[cnt]);
        }
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
            arr[i][j] = toupper(arr[i][j]);
        memset(visit, 0, sizeof(visit));
        scanf("%d %d", &a, &b);
        ch = arr[a][b];
        if(ch == 'a')
            ch2 = 'b';
        else
            ch2 = 'a';
        row = a;
        column = b;
        arr[a][b] = ch2;
        BFS();
        x = 0;
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
            {
                if(arr[i][j] == ch)
                {
                    arr[i][j] = ch2;
                    row = i;
                    column = j;
                    total = 1;
                    BFS();
                    if(x < total)
                        x = total;
                }
            }
        printf("%d\n\n", x);
    }
    return 0;
}
