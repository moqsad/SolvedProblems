#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    int count, sum, x, y, i;
    char arr[12];
    while(1)
    {
        scanf("%s", arr);
        if(arr[0] == '-' && arr[1] != '0')
        break;
        sum = 0;
        i = 0;
        if(arr[0] == '0' && arr[1] == 'x')
        {
            for(count = strlen(arr) - 1; count >= 2; --count)
            {
                if(arr[count] >= '0' && arr[count] <= '9')
                {
                sum += ceil((arr[count] - 48) *  pow(16.0, (double)i));
                       ++i;
                }
                else
                {
                sum += ceil((arr[count] - 65 + 10) *  pow(16.0, (double)i));
                       ++i;
                }

            }
            printf("%d\n", sum);
        }
        else
        {
            for(count = strlen(arr) - 1; count >= 0; --count)
            {
                sum += ceil((arr[count] - 48) *  pow(10.0, (double)i));
                       ++i;
            }
            printf("0x%X\n", sum);
        }
    }
    return 0;
}
