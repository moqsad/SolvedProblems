#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

int n, m, row, column, d[205][205], visit[205][205], p[] = {-1, 1, 0, 0}, qq[] = {0, 0, -1, 1};

struct data
{
    int r, c;
};

char arr[205][205];

void func()
{
    int i, j, k, x, y;
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
        {
            if(arr[i][j] == 'F')
            {
                for(k = 0; k < 4; ++k)
                {
                    x = i + p[k];
                    y = j + qq[k];
                    if(x >= 0 && x < n && y >= 0 && y < m && arr[x][y] != '#')
                        arr[x][y] = 'X';
                }
            }
        }

    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
        {
            if(arr[i][j] == 'X')
                arr[i][j] = 'F';
        }
}

void bfs(int cnt)
{
    data info, info2;
    info.r = row;
    info.c = column;
    queue <data> q;
    q.push(info);
    d[row][column] = 0;

    visit[row][column] = 1;

    int i, x, y, z = 1;

    while(!q.empty())
    {
        info2  = q.front();
        if(d[info2.r][info2.c] == z)
        {
            func();
            ++z;
        }

        if((info2.r == 0 || info2.r == n - 1 || info2.c == 0 || info2.c == m - 1) && arr[info2.r][info2.c] != 'F')
        {
            row = info2.r;
            column = info2.c;
            break;
        }
        q.pop();
//        printf("%d %d___\n", info2.r, info2.c);
        if(arr[info2.r][info2.c] != 'F')
            for(i = 0; i < 4; ++i)
            {
                x = info2.r + p[i];
                y = info2.c + qq[i];
                if(x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == '.' && visit[x][y] == 0)
                {
                    d[x][y] = d[info2.r][info2.c] + 1;
                    visit[x][y] = 1;
                    info.r = x;
                    info.c = y;
                    q.push(info);
                }
            }
    }

    if(!q.empty())
        printf("Case %d: %d\n", cnt, d[row][column] + 1);
    else
        printf("Case %d: IMPOSSIBLE\n", cnt);
}

int main()
{
    int t, cnt, i, j, found;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        found = 0;
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; ++i)
        {
            scanf("%s", arr[i]);
            if(found == 0)
            {
                for(j = 0; j < m; ++j)
                {
                    if(arr[i][j] == 'J')
                    {
                        found = 1;
                        row = i;
                        column = j;
                        break;
                    }
                }
            }
        }
        memset(visit, 0, sizeof(visit));
        bfs(cnt);
    }
    return 0;
}
