#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int h, w, row, column, p[] = {0, 0, -1, 1}, q[] = {-1, 1, 0, 0}, r, c, total, num[300];
bool visit[60][60];
char arr[60][60];

queue <int> Qrow;
queue <int> Qcolumn;
queue <int> Qr;
queue <int> Qc;

void BFSS(void)
{
    Qr.push(r);
    Qc.push(c);
    arr[r][c] = '.';
    int x, y, i;
    while(!Qr.empty())
    {
        r = Qr.front();
        c = Qc.front();
        Qr.pop();
        Qc.pop();
        for(i = 0; i < 4; ++i)
        {
            x = r + p[i];
            y = c + q[i];
            if(x >= 0 && x < h && y >= 0 && y < w && arr[x][y] == 'X' && visit[x][y] == 0)
            {
                arr[x][y] = '*';
                Qr.push(x);
                Qc.push(y);
            }
        }
    }
    return;
}

void BFS(void)
{
    Qrow.push(row);
    Qcolumn.push(column);

    if(arr[row][column] == 'X')
    {
        r = row;
        c = column;
        ++total;
        BFSS();
    }

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
            if(x >= 0 && x < h && y >= 0 && y < w && (arr[x][y] == '*' || arr[x][y] == 'X') && visit[x][y] == 0)
            {
                if(arr[x][y] == 'X')
                {
                    Qrow.push(x);
                    Qcolumn.push(y);
                    visit[x][y] = 1;
                    r = x;
                    c = y;
                    ++total;
                    BFSS();
                }
                else if(arr[x][y] == '*')
                {
                    arr[x][y] = '.';
                    Qrow.push(x);
                    Qcolumn.push(y);
                    visit[x][y] = 1;
                }
            }
        }
    }
    return ;
}


int main()
{
    int i, j, k, cnt = 0;
    while(scanf("%d %d", &w, &h) == 2)
    {
        if(w == 0 && h == 0)
            break;
        k = 0;
        memset(visit, 0, sizeof(visit));
        for(i = 0; i < h; ++i)
        {
            scanf("%s", arr[i]);
        }
        for(i = 0; i < h; ++i)
            for(j = 0; j < w; ++j)
            {
                if(arr[i][j] == '*' || arr[i][j] == 'X')
                {
                    row = i;
                    column = j;
                    visit[i][j] = 1;
                    total = 0;
                    BFS();
                    num[k++] = total;
                }
            }
        sort(num, num + k);
        printf("Throw %d\n", ++cnt);
        j = k - 1;
        for(i = 0; i < j; ++i)
            printf("%d ", num[i]);
        printf("%d\n\n", num[i]);
    }
    return 0;
}
