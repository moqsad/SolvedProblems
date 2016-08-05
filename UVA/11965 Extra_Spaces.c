#include <stdio.h>
int main()
{
    int cnt, i, j, n, k, p;
    char arr[60][550];
    scanf("%d", &n);
    p = 0;
    for(cnt = 1; cnt <= n; ++cnt)
    {
        scanf("%d", &k);
        getchar();
        for(i = 0; i < k; ++i)
        {
            gets(arr[i]);
        }
        printf("Case %d:\n", cnt);
        for(i = 0; i < k; ++i)
        {
            j = 0;
            while(arr[i][j] != '\0')
            {
                if(arr[i][j] == ' '||arr[i][j]=='\t')
                {
                    while(arr[i][j] == ' '||arr[i][j]=='\t')
                        ++j;
                    putchar(' ');
                }
                else
                {
                    putchar(arr[i][j]);
                    ++j;
                }
            }
            printf("\n");
        }
        if(cnt <= n - 1)
            printf("\n");
    }
    return 0;
}
