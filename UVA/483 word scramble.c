#include <stdio.h>
int main()
{
    int count, i, k;
    char arr[1000], word[100];
    while(gets(arr))
    {
        if(arr[0] == EOF )
        break;
        count = 0;
        while(arr[count] != '\0')
        {
            i = 0;
            if(arr[count] != ' ' && arr[count] != '\0')
            {
                while(arr[count] != ' ' && arr[count] != '\0')
                {
                if(arr[count + 1] == ' ' || arr[count + 1] == '\0')
                {
                    word[i] = arr[count];
                    k = i;
                    for(i = k; i >= 0; --i)
                    putchar(word[i]);
                    ++count;
                    break;
                }
                word[i] = arr[count];
                ++count;
                ++i;
                }
            }
            else
            {
            putchar(arr[count]);
            ++count;
            }

        }
        printf("\n");
    }
    return 0;
}
