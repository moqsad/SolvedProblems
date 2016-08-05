#include <stdio.h>
#include <string.h>
int main()
{
    int count = 0;
    char arr[10];
    while(1)
    {
        gets(arr);
        if(arr[0] == '*' && strlen(arr) == 1)
            break;
            ++count;
        if(strcmp(arr, "Hajj") == 0)
            printf("Case %d: Hajj-e-Akbar\n", count);
        else
            printf("Case %d: Hajj-e-Asghar\n", count);
    }
    return 0;
}
