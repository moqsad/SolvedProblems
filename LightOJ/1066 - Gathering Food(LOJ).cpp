#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;

char arr[12][12], end_;
int r, c, d[12][12], visit[12][12], n, p[] = {-1, 1, 0, 0}, qq[] = {0, 0, -1, 1};

struct data
{
    int row;
    int column;
};

void bfs(void)
{
    queue <data> q;
    data info, info2;
    int i, x, y;
    info.row = r;
    info.column = c;
    d[r][c] = 0;
    visit[r][c] = 1;
    arr[r][c] = '.';
    q.push(info);
    while(!q.empty())
    {
        info2 = q.front();
        if(arr[info2.row][info2.column] == end_)
        {
            r = info2.row;
            c = info2.column;
            break;
        }

        q.pop();

        for(i = 0; i < 4; ++i)
        {
            x = info2.row + p[i];
            y = info2.column + qq[i];
            if(x >= 0 && x < n && y >= 0 && y < n && arr[x][y] != '#' && visit[x][y] == 0)
            {
                if(!(arr[x][y] >= 'A' && arr[x][y] <= 'Z' && arr[x][y] != end_))
                {
                    visit[x][y] = 1;
                    d[x][y] = d[info2.row][info2.column] + 1;
                    info.row = x;
                    info.column = y;
                    q.push(info);
                }
            }
        }
    }
}

int main()
{
    int t, cnt, i, j, x, move_;
    char min_ = 'A', max_;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        max_ = '0';
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%s", arr[i]);
            for(j = 0; j < n; ++j)
            {
                if(arr[i][j] >= 'A' && arr[i][j] <= 'Z')
                {
                    if(arr[i][j] == min_)
                    {
                        r = i;
                        c = j;
                    }

                    if(arr[i][j] > max_)
                        max_ = arr[i][j];
                }
            }
        }

        move_ = 0;
        x = max_ - min_;
        for(i = 1; i <= x; ++i)
        {
            memset(d, 0, sizeof(d));
            memset(visit, 0, sizeof(visit));

            end_ = min_ + i;
            bfs();
            if(d[r][c] > 0)
                move_ += d[r][c];
            else
                break;
        }

        if(i > x)
            printf("Case %d: %d\n", cnt, move_);
        else
            printf("Case %d: Impossible\n", cnt);
    }
    return 0;
}

