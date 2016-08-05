#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    long long count, sum, i, k;
    char arr[1000];
    while(1)
    {
        scanf("%s", arr);
        if(arr[0] == '0'&& strlen(arr) == 1)
            break;
        sum = 0;
        i = 0;
        for(count = strlen(arr) - 1; count >= 0; --count)
        {
            k = count + 1;
            sum += (arr[i] - 48) * (pow(2, k) - 1);
            ++i;
        }
        printf("%d\n", sum);
    }
}
