#include <stdio.h>
#include <string.h>
int main()
{
    int count, i, k, p;
    char arr[1000];
    while(1)
    {
        gets(arr);
        if(strcmp(arr, "DONE") == 0 && strlen(arr) == 4)
            break;
        i = 0;
        for(count = 0; count < strlen(arr); ++count)
        {
            if((arr[count] >= 'a' && arr[count] <= 'z') || (arr[count] >= 'A' && arr[count] <= 'Z'))
            {
                arr[i] = tolower(arr[count]);
                ++i;
            }
        }
        arr[i] = '\0';
        k = i;
        p = 1;
        for(count = 0, i = k - 1; count < k / 2; ++count, --i)
            if(arr[count] != arr[i])
            {
                printf("Uh oh..\n");
                p = 0;
                break;
            }
        if(p == 1)
            printf("You won't be eaten!\n");
    }
    return 0;
}
