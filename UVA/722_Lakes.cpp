#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char letter[10], arr[110][110];
int m, n, total, p[] = {-1, 1, 0, 0}, q[] = {0, 0, -1, 1};

void dfs(int a, int b)
{
    int i, x, y;
    ++total;
    arr[a][b] = '1';
    for(i = 0; i < 4; ++i)
    {
        x = a + p[i];
        y = b + q[i];
        if(x >= 0 && x < n && y >= 0 && y < m && arr[x][y] == '0')
            dfs(x, y);
    }
}

int main()
{
    int t, cnt, a, b;
    scanf("%d\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        gets(letter);
        sscanf(letter, "%d %d", &a, &b);
//        printf("%d %d____\n", a, b);
        n = 0;
        while(gets(arr[n]))
        {
            if(arr[n][0] == '\0')
                break;
            ++n;
        }
        m = strlen(arr[0]);
        total = 0;
        dfs(a - 1, b - 1);
        printf("%d\n", total);
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
