#include "bits/stdc++.h"
using namespace std;

queue <int> Qrow;
queue <int> Qcolumn;

int p[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, q[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int r[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, s[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int startrow, startcolumn, finishrow, finishcolumn, dist[1500][1500], visit[1500][1500], m, n;
char arr[1500][1500];

void BFS(void)
{
    memset(visit, 0, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    while(!Qrow.empty())
    {
        Qrow.pop();
        Qcolumn.pop();
    }

    visit[startrow][startcolumn] = 1;
    dist[startrow][startcolumn] = 0;
    Qrow.push(startrow);
    Qcolumn.push(startcolumn);

    int row, column, i, x, y, p = 0;

    while(!Qrow.empty())
    {
        row = Qrow.front();
        column = Qcolumn.front();
        Qrow.pop();
        Qcolumn.pop();
        for(i = 0; i < 8; ++i)
        {
            x = row + r[i];
            y = column + s[i];
            if((x >= 0 && x < m) && (y >= 0 && y < n))
            {
                if((arr[x][y] == '.' || arr[x][y] == 'B') && visit[x][y] == 0)
                {
                    dist[x][y] = dist[row][column] + 1;
                    if(arr[x][y] == 'B')
                    {
                        p = 1;
                        break;
                    }
                    visit[x][y] = 1;
                    Qrow.push(x);
                    Qcolumn.push(y);
                }
            }
        }
        if(p == 1)
            break;
    }
    return ;
}

int main()
{
    int t, cnt, i, j, k, x, y;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d %d", &m, &n);
        for(i = 0; i < m; ++i)
        {
            scanf("%s", arr[i]);
        }
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
            {
                if(arr[i][j] == 'Z')
                {
                    for(k = 0; k < 8; ++k)
                    {
                        x = i + p[k];
                        y = j + q[k];
                        if((x >= 0 && x < m) && (y >= 0 && y < n) && arr[x][y] != 'A' && arr[x][y] != 'B')
                        {
                            if(arr[x][y] == '.')
                                arr[x][y] = '*';
                        }
                    }
                }
                else if(arr[i][j] == 'A')
                {
                    startrow = i;
                    startcolumn = j;
                }
                else if(arr[i][j] == 'B')
                {
                    finishrow = i;
                    finishcolumn = j;
                }
            }
        BFS();
        if(dist[finishrow][finishcolumn] > 0)
            printf("Minimal possible length of a trip is %d\n", dist[finishrow][finishcolumn]);
        else
            printf("King Peter, you can't go now!\n");
    }
    return 0;
}

