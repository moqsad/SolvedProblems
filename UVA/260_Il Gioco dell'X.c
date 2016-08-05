#include <stdio.h>
#include <string.h>

int x[] = {-1, 0, 1, -1, 0, 1};
int y[] = {-1, -1, 0, 0, 1, 1};

int n;

void dfs(char arr[][300], int i, int cnt);
int main()
{
    int cnt, i, det = 0, p, x, j;
    char arr[300][300];
    while(scanf("%d", &n)==1)
    {
        p = 0;
        if(n == 0)
            break;
        for(cnt = 0; cnt < n; ++cnt)
        {
            scanf("%s", arr[cnt]);
        }
        x = n - 1;
        for(cnt = 0; cnt < n; ++cnt)
        {
            i = 0;
            if(arr[i][cnt] == 'b')
            {
                dfs(arr, i, cnt);
                for(j = 0; j < n; ++j)
                    if(arr[x][j] == '*')
                    {
                        p = 1;
                        break;
                    }
            }
            if(p == 1)
                break;
        }
        ++det;
        if(p == 1)
            printf("%d B\n", det);
        else
            printf("%d W\n", det);
    }
    return 0;
}
void dfs(char arr[][300], int i, int cnt)
{
    int p, u, v;
    if(i < n && cnt < n && i > -1 && cnt > -1)
    {
        if(arr[i][cnt] == 'b')
        {
            arr[i][cnt] = '*';
            for(p = 0; p < 6; ++p)
            {
                u = i + x[p];
                v = cnt + y[p];
                dfs(arr, u, v);
            }
        }
    }
    return;
}
