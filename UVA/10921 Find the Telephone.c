#include <stdio.h>
int main()
{
    char arr[31];
    int count;
    while(scanf(" %[^\n]", arr) == 1)
    {
        count = 0;
        while(arr[count] != '\0')
        {
            if(arr[count] == 'A' || arr[count] == 'B' || arr[count] == 'C')
                arr[count] = '2';
            else if(arr[count] == 'D' || arr[count] == 'E' || arr[count] == 'F')
                arr[count] = '3';
            else if(arr[count] == 'G' || arr[count] == 'H' || arr[count] == 'I')
                arr[count] = '4';
            else if(arr[count] == 'J' || arr[count] == 'K' || arr[count] == 'L')
                arr[count] = '5';
            else if(arr[count] == 'M' || arr[count] == 'N' || arr[count] == 'O')
                arr[count] = '6';
            else if(arr[count] == 'P' || arr[count] == 'Q' || arr[count] == 'R' || arr[count] == 'S')
                arr[count] = '7';
            else if(arr[count] == 'T' || arr[count] == 'U' || arr[count] == 'V')
                arr[count] = '8';
            else if(arr[count] == 'W' || arr[count] == 'X' || arr[count] == 'Y' || arr[count] == 'Z')
                arr[count] = '9';
            ++count;
        }
        printf("%s\n", arr);
    }
    return 0;
}
