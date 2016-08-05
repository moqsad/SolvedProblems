#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;


char line[1010], arr[510][510];
int visit[510][510], p[] = {-1, -1, -1, 0, 0, 1, 1, 1}, q[] = {-1, 0, 1, -1, 1, -1, 0, 1}, now, n, m, digit, max_[510];

void dfs(int a, int b, char c)
{
    int i, x, y;
    visit[a][b] = now;
    for(i = 0; i < 8; ++i)
    {
        x = a + p[i];
        y = b + q[i];
        if(x >= 1 && x <= n && y >= 1 && y <= m && visit[x][y] == 0 && arr[x][y] == c)
        {
            dfs(x, y, c);
        }
    }
}

void space_print(int a, int b, int c)
{
    int i = 0, j = 0, k;
    while(a > 0)
    {
        ++i;
        a /= 10;
    }
    while(c > 0)
    {
        ++j;
        c /= 10;
    }
    i = j - i + 1;
    if(b == 1)
        --i;
    for(k = 1; k <= i; ++k)
        printf(" ");
}

void print(void)
{
    int i, j;
    digit = 0;
    for(i = 1; i <= n; ++i)
    {
        for(j = 1; j <= m; ++j)
        {
            space_print(visit[i][j], j, max_[j]);
            printf("%d", visit[i][j]);
        }
        printf("\n");
    }
    printf("%%\n");
}

int main()
{
    int k, l;
    while(gets(line))
    {
        if(line[0] != '%')
        {
            m = 0;
            stringstream sin (line);
            ++n;
            while(sin >> arr[n][++m]);
        }

        else
        {
            memset(visit, 0, sizeof(visit));
            memset(max_, 0, sizeof(max_));
            now = 0;
            --m;
            for(k = 1; k <= n; ++k)
                for(l = 1; l <= m; ++l)
                {
                    if(visit[k][l] == 0)
                    {
                        ++now;
                        dfs(k, l, arr[k][l]);
                    }
                    if(visit[k][l] > max_[l])
                        max_[l] = visit[k][l];
                }
            print();
            n = 0;
        }
    }

    memset(visit, 0, sizeof(visit));
    memset(max_, 0, sizeof(max_));
    now = 0;
    --m;
    for(k = 1; k <= n; ++k)
        for(l = 1; l <= m; ++l)
        {
            if(visit[k][l] == 0)
            {
                ++now;
                dfs(k, l, arr[k][l]);
            }
            if(visit[k][l] > max_[l])
                max_[l] = visit[k][l];
        }
    print();
    return 0;
}
