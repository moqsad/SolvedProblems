#include <stdio.h>
#include <string.h>
int main()
{
    int x, i, y, z;
    char arr[100500];
    while((scanf("%s", arr)) == 1)
    {
        x = strlen(arr) - 1;
        z = strlen(arr);
        for(i = x; i >= 0; --i)
        {
            if(arr[i] == '[')
            {
                arr[i] = '0';
                y = i;
                while(1)
                {
                    ++y;
                    if(arr[y] == ']')
                    {
                        arr[y] = '0';
                        break;
                    }
                    else if(arr[y] == '\0' || arr[y] == '0')
                        break;
                    else
                    {
                        putchar(arr[y]);
                        arr[y] = '0';
                    }
                }
            }
        }
        for(i = 0; i < z; ++i)
        {
            if(arr[i] != '0' && arr[i] != ']')
                putchar(arr[i]);
        }
        printf("\n");
    }
    return 0;
}
