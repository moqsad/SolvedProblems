#include <stdio.h>
#include <string.h>
int main()
{
    int count, n, i, j, p;
    char arr[4][50];
    scanf("%d", &n);
    getchar();
    for(count = 1; count <= n; ++count)
    {
        gets(arr[0]);
        gets(arr[1]);
        while(1)
        {
        if(strcmp(arr[0], arr[1]) == 0)
        {
            printf("Case %d: Yes\n", count);
            break;
        }
        j = 0;
        for(i = 0; i <= strlen(arr[0]); ++i)
        {
            if(arr[0][i] != ' ')
            {
                arr[0][j] = arr[0][i];
                ++j;
            }
        }
        j = 0;
        for(i = 0; i <= strlen(arr[1]); ++i)
        {
            if(arr[1][i] != ' ')
            {
                arr[1][j] = arr[1][i];
                ++j;
            }
        }
        if(strcmp(arr[0], arr[1]) != 0)
            printf("Case %d: Wrong Answer\n", count);
        else
        printf("Case %d: Output Format Error\n", count);
        break;
        }
    }
    return 0;
}
