#include <stdio.h>
#include <string.h>
int main()
{
    int count, odd, even;
    char arr[1050];
    while(1)
    {
        odd = 0;
        even = 0;
        gets(arr);
        if(arr[0] == '0' && strlen(arr) == 1)
        break;
        for(count = 1; count < strlen(arr); count += 2)
        even += arr[count] - 48;
        for(count = 0; count < strlen(arr); count += 2)
        odd += arr[count] - 48;
        if(arr[0] != '\0')
        if((even - odd) % 11 == 0)
        printf("%s is a multiple of 11.", arr);
        else
        printf("%s is not a multiple of 11.", arr);
        printf("\n");
    }
    return 0;
}
