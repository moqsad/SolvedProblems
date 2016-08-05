#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n;

void dfs(int u, int arr[][30], int num[])
{
    if(num[u] == 1)
        return;
    num[u] = 1;
    int i;
    for(i = 0; i < n; ++i)
    {
        if(arr[u][i] == 1)
        {
            arr[u][i] = 0;
            dfs(i, arr, num);
        }
    }
    return;
}

int main()
{
    int cnt, t, arr[30][30], i, j, k, num[30];
    char ch, letter[5];
    scanf("%d\n\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        k = 0;
        scanf("%c", &ch);
        getchar();
        n = ch - 64;
        memset(arr, 0, sizeof(arr));
        memset(num, 0, sizeof(num));
        for(i = 0; i < n; ++i)
            arr[i][i] = 1;
        while(gets(letter))
        {
            if(letter[0] == '\0')
                break;
            arr[letter[0] - 65][letter[1] - 65] = 1;
            arr[letter[1] - 65][letter[0] - 65] = 1;
        }
        for(i = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
            {
                if(arr[i][j] == 1)
                {
                    ++k;
                    dfs(i, arr, num);
                }
            }
        printf("%d\n", k);
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
