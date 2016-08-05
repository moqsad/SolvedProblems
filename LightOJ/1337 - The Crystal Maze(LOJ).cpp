#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char arr[505][505];
int p[4] = {-1, 1,  0, 0}, q[4] = {0, 0, -1, 1}, n, m, dp[505][505], visit[505][505], visit2[505][505], value;

int dfs(int r, int c)
{
    int ans = 0, i, x, y;
    if(arr[r][c] == 'C')
        ans = 1;
    visit[r][c] = 1;
    for(i = 0; i < 4; ++i)
    {
        x = r + p[i];
        y = c + q[i];
        if(x >= 0 && x < m && y >= 0 && y < n && arr[x][y] != '#' && visit[x][y] == 0)
        {
            ans += dfs(x, y);
        }
    }
    return ans;
}

void dfs2(int r, int c)
{
    int ans = 0, i, x, y;
//    printf("%d %d_____________\n", r, c);
    dp[r][c] = value;
    visit2[r][c] = 1;
    for(i = 0; i < 4; ++i)
    {
        x = r + p[i];
        y = c + q[i];
        if(x >= 0 && x < m && y >= 0 && y < n && arr[x][y] != '#' && visit2[x][y] == 0)
        {
            dfs2(x, y);
        }
    }
}

int main()
{
    int t, cnt, r, c, i, qq;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d", &m, &n, &qq);
        for(i = 0; i < m; ++i)
        {
            scanf("%s", arr[i]);
        }

        printf("Case %d:\n", cnt);
        memset(dp, -1, sizeof(dp));
        memset(visit, 0, sizeof(visit));
        memset(visit2, 0, sizeof(visit2));

        for(i = 0; i < qq; ++i)
        {
            scanf("%d %d", &r, &c);
            if(dp[r - 1][c - 1] == -1)
            {
                value = dfs(r - 1, c - 1);
                dfs2(r - 1, c - 1);
            }
            else
               value = dp[r - 1][c - 1];
            printf("%d\n", value);
        }
    }
    return 0;
}

/*
1
4 5 5
..#..
.C#C.
##..#
..C#C
1 1
4 1
*/
