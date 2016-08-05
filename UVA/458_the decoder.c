#include <stdio.h>
#include <string.h>
int main()
{
    char arr[100];
    int count;
    while(scanf(" %[^\n]", &arr) == 1)
    {
        for(count = 0; count < strlen(arr); ++count)
            printf("%c", arr[count] - 7);
            printf("\n");
    }
    return 0;
}
