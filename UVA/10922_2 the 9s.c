#include <stdio.h>
int main()
{
    int sum, count, a;
    char arr[1001];
    while(1)
    {
        scanf("%s", arr);
        if(arr[0] == '0')
            break;
            sum = 0;
            count = 0;
        while(arr[count] != '\0')
            sum += arr[count++] - 48;
        if(sum % 9 == 0)
        {
            for(count = 1; !(sum >= 0 && sum <= 9); ++count)
            {
                a = sum;
                sum = 0;
                while(!(a >= 0 && a <= 9))
                {
                    sum += a % 10;
                    a /= 10;
                }
            }
            printf("%s is a multiple of 9 and has 9-degree %d.\n", arr, count);
        }
        else
        printf("%s is not a multiple of 9.\n", arr);
    }
    return 0;
}
