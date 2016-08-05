#include <stdio.h>
#include <string.h>
int num[2050];
int main()
{
    int count, i, j, k, p, x, temp, n;
    char arr[2050][80], letter[80], input[80];
    scanf("%d\n", &n);
    for(count = 0; count < n; ++count)
        arr[count][0] = '\0';
    j = 0;
    for(count = 1; count <= n; ++count)
    {
        gets(input);
        i = 0;
        while(input[i] != ' ')
        {
            letter[i] = input[i];
            ++i;
        }
        letter[i] = '\0';
        p = 0;
        for(k = 0; k < j; ++k)
            if(strcmp(arr[k], letter) == 0)
            {
                p = 1;
                ++num[k];
                break;
            }
        if(p == 0)
        {
            num[j] = 1;
            strcpy(arr[j], letter);
            ++j;
        }
    }
    x = j - 1;
    for(count = 0; count < x; ++count)
        for(i = count + 1; i < j; ++i)
        {
            if(strcmp(arr[count], arr[i]) > 0)
            {
                strcpy(letter, arr[count]);
                strcpy(arr[count], arr[i]);
                strcpy(arr[i], letter);
                temp = num[count];
                num[count] = num[i];
                num[i] = temp;
            }
        }
    for(count = 0; count < j; ++count)
    {
        printf("%s %d\n", arr[count], num[count]);
    }
    return 0;
}
