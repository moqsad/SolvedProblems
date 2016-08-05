#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int count, p, a, sum;
    char arr[100];
    while(gets(arr))
    {
        if(arr[0] == 'a' && strlen(arr) == 1)
            printf("It is not a prime word.");
        else if(arr[0] == 'b' && strlen(arr) == 1)
            printf("It is a prime word.");
        else
        {
            count = 0;
            sum = 0;
            while(arr[count] != '\0')
            {
                if(('a' <= arr[count] && arr[count] <= 'z') || ('A' <= arr[count] && arr[count] <= 'Z'))
                {
                    if(arr[count] >= 'a')
                        sum += arr[count] - 96;
                    else
                        sum += arr[count] - 65 + 27;
                }
                ++count;
            }
            a = sqrt(sum) - 1;
            p = 1;
            for(count = 2; count <= a + 2; ++count)
                if(sum % count == 0)
                {
                    p = 0;
                    printf("It is not a prime word.");
                    break;
                }
            if(p == 1 && arr[0] != '\0')
                printf("It is a prime word.");
        }
        printf("\n");
    }
    return 0;
}
