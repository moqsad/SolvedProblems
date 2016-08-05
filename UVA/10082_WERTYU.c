#include  <stdio.h>
#include <string.h>
int main()
{
    int count, i, k;
    char arr[100], letter[] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
    while(gets(arr))
    {
        if(arr[0] == EOF)
        break;
        count = 0;
        while(arr[count] != '\0')
        {
            k = 1;
            for(i = 0; i < strlen(letter); ++i)
            if(arr[count] == letter[i])
            {
                putchar(letter[i - 1]);
                k = 0;
                break;
            }
            if(k == 1)
            putchar(' ');
            ++count;
        }
        printf("\n");
    }
    return 0;
}
