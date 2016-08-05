#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

int m, n;
char ch;

void dfs(char arr[][102], int i, int j, int m, int n);
int main()
{
    int cnt, i, j, num, value[26], k, r, s;
    scanf("%d", &num);
    for(cnt = 1; cnt <= num; ++cnt)
    {
        memset(value, 0, sizeof(value));
        scanf("%d %d", &m, &n);
        char arr[m][102], letter[] = "abcdefghijklmnopqrstuvwxyz";
        for(j = 0; j < m; ++j)
        {
            scanf("%s", arr[j]);
        }
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
                if(arr[i][j] != '0')
                {
                    for(k = 0; k < 26; ++k)
                        if(arr[i][j] == letter[k])
                        {
                            ++value[k];
                            ch = arr[i][j];
                            dfs(arr, i, j, m, n);
                            break;
                        }
                }
        printf("World #%d\n", cnt);
        for(i = 0; i < 26; ++i)
        {
            r = 0;
            s = 0;
            for(j = 0; j < 26; ++j)
                if(value[j] > r)
                {
                    r = value[j];
                    s = j;
                }
            value[s] = 0;
            if(r == 0)
                break;
            printf("%c: %d\n", letter[s], r);
        }
    }
    return 0;
}
void dfs(char arr[][102], int i, int j, int m, int n)
{
    int p, u, v;
    if(i < m && j < n && i > -1 && j > -1)
        if(arr[i][j] == ch)
        {
            arr[i][j] = '0';
            for(p = 0; p < 4; ++p)
            {
                u = i + x[p];
                v = j + y[p];
                dfs(arr, u, v, m, n);
            }
        }
    return;
}
