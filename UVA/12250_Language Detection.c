#include <stdio.h>
#include <string.h>
int main()
{
    int count = 0;
    char arr[20];
    while(1)
    {
        gets(arr);
        if(arr[0] == '#' && strlen(arr) == 1)
            break;
            ++count;
        if(strcmp(arr, "HELLO") == 0)
            printf("Case %d: ENGLISH\n", count);
        else if(strcmp(arr, "HOLA") == 0)
            printf("Case %d: SPANISH\n", count);
        else if(strcmp(arr, "HALLO") == 0)
            printf("Case %d: GERMAN\n", count);
        else if(strcmp(arr, "BONJOUR") == 0)
            printf("Case %d: FRENCH\n", count);
        else if(strcmp(arr, "CIAO") == 0)
            printf("Case %d: ITALIAN\n", count);
        else if(strcmp(arr, "ZDRAVSTVUJTE") == 0)
            printf("Case %d: RUSSIAN\n", count);
        else
            printf("Case %d: UNKNOWN\n", count);
            getchar();
    }
    return 0;
}
