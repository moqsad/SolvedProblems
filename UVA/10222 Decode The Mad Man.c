#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int cnt, i, p;
    char arr[1000], letter[] = "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./`1234567890-=";
    gets(arr);
    cnt = 0;
    while(arr[cnt] != '\0')
    {
        p = 0;
        for(i = 0; i < strlen(letter); ++i)
        {
            if(tolower(arr[cnt]) == letter[i])
            {
                p = 1;
                putchar(letter[i - 2]);
                break;
            }
        }
        if(p == 0)
        putchar(' ');
        ++cnt;
    }
    printf("\n");
    return 0;
}
