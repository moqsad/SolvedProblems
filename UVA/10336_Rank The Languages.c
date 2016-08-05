#include <stdio.h>
#include <ctype.h>
int main()
{
    int t, m, n, num[27], i, j, k, temp, x, count, p;
    char arr[200][200], letter[] = "?abcdefghijklmnopqrstuvwxyz";
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%d %d", &m, &n);
        for(i = 0; i < m; ++i)
            scanf("%s", arr[i]);
        for(i = 1; i < 27; ++i)
            num[i] = 0;
        for(i = 0; i < m; ++i)
            for(j = 0; j < n; ++j)
            {
                p = 1;
                if((i - 1 >= 0 && i - 1 < m) && (arr[i - 1][j] == toupper(arr[i][j])))
                {
                    p = 0;
                }
                if(p == 1 && (i + 1 >= 0 && i + 1 < m) && (arr[i + 1][j] == toupper(arr[i][j])))
                {
                    p = 0;
                }
                if(p == 1 && (j - 1 >= 0 && j - 1 < n) && (arr[i][j - 1] == toupper(arr[i][j])))
                {
                    p = 0;
                }
                if(p == 1 && (j + 1 >= 0 && j + 1 < n) && (arr[i][j + 1] == toupper(arr[i][j])))
                {
                    p = 0;
                }
                if(p == 1)
                {
                    for(k = 1; k < 27; ++k)
                    {
                        if(arr[i][j] == letter[k])
                        {
                            printf("%d %d______________\n", i, j);
                            ++num[k];
                        }
                    }
                }
                else if(((i - 1 >= 0 && i - 1 < m) && (arr[i - 1][j] == toupper(arr[i][j]))) && ((j - 1 >= 0 && j - 1 < n) && (arr[i][j - 1] == toupper(arr[i][j]))))
                {
                     for(k = 1; k < 27; ++k)
                    {
                        if(arr[i][j] == letter[k])
                        {
                            printf("%d %d%%%%%%%%%%%%%%%%%%%\n", i, j);
                            --num[k];
                        }
                    }
                }
                arr[i][j] = toupper(arr[i][j]);
            }
        printf("World #%d\n", count);
        for(i = 1; i < 27; ++i)
        {
            x = 1;
            for(j = 2; j < 27; ++j)
            {
                if(num[x] < num[j])
                {
                    x = j;
                }
            }
            if(num[x] == 0)
                break;
            else
            {
                printf("%c %d\n", letter[x], num[x]);
                num[x] = 0;
            }
        }
    }
    return 0;
}
