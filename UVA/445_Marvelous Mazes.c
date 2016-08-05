#include <stdio.h>
int main()
{
    int i, count, x, j = 1, k = 0, p = 0;
    char arr[150];
    while(gets(arr))
    {
        if(arr[0] != '\0')
        {
            ++p;
            k = p;
        }
        else
            ++k;
        if(k - p == 1)
        {
                printf("\n");
        }
        if(arr[0] != '\0')
        {
            count = 0;
            while(arr[count] != '\0')
            {
                if(arr[count] == '*')
                {
                    putchar('*');
                    ++count;
                }
                else if(arr[count] == '!')
                {
                    printf("\n");
                    ++count;
                }
                else
                {
                    x = 0;
                    while(arr[count] >= '0' && arr[count] <= '9')
                    {
                        x += arr[count] - 48;
                        ++count;
                    }
                    if(arr[count] == 'b')
                        arr[count] = ' ';
                    for(i = 0; i < x; ++i)
                    {
                        putchar(arr[count]);
                    }
                    ++count;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
