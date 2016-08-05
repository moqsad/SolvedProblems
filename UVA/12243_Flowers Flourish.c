#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int count, i, p;
    char arr[1500], x, y;
    while(1)
    {
        gets(arr);
        if(arr[0] == '*' && strlen(arr) == 1)
            break;
        x = tolower(arr[0]);
        count = 0;
        p = 1;
        while(arr[count] != '\0')
        {
            y = tolower(arr[count]);
            if(y >= 'a' && y <= 'z')
            {
                if(y != x)
                {
                    p = 0;
                    break;
                }
                while(y >= 'a' && y <= 'z')
                {
                    ++count;
                    y = tolower(arr[count]);
                }
            }
            else
            {
             ++count;
            }
        }
        if(p == 1)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
