#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

int total, m, n, p[] = {-1, -1, -1, 0, 0, 1, 1, 1}, q[] = {-1, 0, 1, -1, 1, -1, 0, 1};
char arr[110][110], letter[110], a[110], b[110];
bool visit[110][110];

void dfs(int a, int b)
{
    int i, x, y;
    visit[a][b] = 1;
    ++total;
    for(i = 0; i < 8; ++i)
    {
        x = a + p[i];
        y = b + q[i];
        if(x >= 1 && x <= n && y >= 0 && y < m)
        {
            if(arr[x][y] == 'W' && visit[x][y] == 0)
                dfs(x, y);
        }
    }
    return ;
}

int main()
{
    int t, cnt, i, j;
    scanf("%d\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        i = 0;
        while(gets(arr[++i]))
            if(!(arr[i][0] == 'L' || arr[i][0] == 'W'))
                break;
        n = i - 1;
        m = strlen(arr[1]);
        sscanf(arr[i], "%s %s", a, b);
        i = atoi(a);
        j = atoi(b);
        total = 0;
        memset(visit, 0, sizeof(visit));
        dfs(i, j - 1);
        printf("%d\n", total);
        while(gets(letter))
        {
            if(letter[0] == '\0')
                break;
            sscanf(letter, "%s %s", a, b);
            i = atoi(a);
            j = atoi(b);
            total = 0;
            memset(visit, 0, sizeof(visit));
            dfs(i, j - 1);
            printf("%d\n", total);
        }
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
