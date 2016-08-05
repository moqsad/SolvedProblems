#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int total;
char arr[25][25];
int p[] = {-1, 1, 0, 0}, q[] = {0, 0, -1, 1}, n, m;
bool visit[25][25];

void dfs(int row, int column)
{
    int i, x, y;
    for(i = 0; i < 4; ++i)
    {
        x = p[i] + row;
        y = q[i] + column;
        if(x >= 0 && x < n && y >= 0 && y < m && visit[x][y] == 0 && arr[x][y] == '.')
        {
            ++total;
            visit[x][y] = 1;
            dfs(x, y);
        }
    }
}

int main()
{
    int t, i, j, cnt, p;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        total = 0;
        memset(visit, 0, sizeof(visit));
        scanf("%d %d", &m, &n);
        for(i = 0; i < n; ++i)
            scanf("%s", arr[i]);
        p = 0;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < m; ++j)
            {
                if(arr[i][j] == '@')
                {
                    ++total;
                    visit[i][j] = 1;
                    dfs(i, j);
                    p = 1;
                    break;
                }
            }
            if(p == 1)
                break;
        }
        printf("Case %d: %d\n", cnt, total);
    }
    return 0;
}
