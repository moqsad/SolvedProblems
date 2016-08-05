
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

queue <int> q;

int n, m, d[1005][1005], p[] = {-1, 1, 0, 0}, qq[] = {0, 0, -1, 1};

char arr[1005][1005];

void bfs(void)
{
    int i, r, c, x, y;
    while(!q.empty())
    {
        r = q.front();
        q.pop();
        c = q.front();

//        printf("%d %d__\n", r, c);

        if((r == 0 || c == 0 || r == n - 1 || c == m - 1) && arr[r][c] == 'J')
            break;

        q.pop();

        if(arr[r][c] == 'J')
            for(i = 0; i < 4; ++i)
            {
                x = r +  p[i];
                y = c + qq[i];
                if(x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == '.')
                {
                    d[x][y] = d[r][c] + 1;
                    arr[x][y] = 'J';
                    q.push(x);
                    q.push(y);
                }
            }

        else
        {
            for(i = 0; i < 4; ++i)
            {
                x = r +  p[i];
                y = c + qq[i];
                if(x >= 0 && x < n && y >= 0 && y < m && (arr[x][y] == '.' || arr[x][y] == 'J'))
                {
                    arr[x][y] = 'F';
                    q.push(x);
                    q.push(y);
                }
            }
        }
    }

    if(!q.empty())
        printf("%d\n", d[r][c] + 1);
    else
        printf("IMPOSSIBLE\n");
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
                        d[i][j] = 0;
                        q.push(i);
                        q.push(j);
                        break;
                    }
                }
            }
        }

        for(i = 0; i < n; ++i)
        {
            for(j = 0; j < m; ++j)
            {
                if(arr[i][j] == 'F')
                {
                    q.push(i);
                    q.push(j);
                }
            }
        }

        bfs();

        while(!q.empty())
            q.pop();
    }
    return 0;
}

