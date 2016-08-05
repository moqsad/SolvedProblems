#include <stdio.h>
int main()
{
    int count, i = 0, x;
    char arr[100];
    while(gets(arr))
    {
        count = 0;
        while(arr[count] != '\0')
        {
            if(arr[count] == '"')
            {
                ++i;
                if(i % 2 == 1)
                    printf("%c%c", '`', '`');
                else
                    printf("%c%c", '\'', '\'');
            }
            else
                putchar(arr[count]);
            ++count;
        }
    printf("\n");
    }
    return 0;
}
