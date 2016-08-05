#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    long long int i, n, j, cnt, sum1, sum2, x;
    char arr1[35], arr2[35];
    scanf("%lld", &n);
    for(cnt = 1; cnt <= n; ++cnt)
    {
        scanf("%s %s", arr1, arr2);
        sum1 = 0;
        sum2 = 0;
        x = strlen(arr1);
        j = x - 1;
        for(i = 0; i < x; ++i)
        {
            if(arr1[i] == '1')
                sum1 += pow(2, j);
            --j;
        }
        x = strlen(arr2);
        j = x - 1;
        for(i = 0; i < x; ++i)
        {
            if(arr2[i] == '1')
                sum2 += pow(2, j);
            --j;
        }
        while(sum2 > 0)
        {
            x = sum1 % sum2;
            sum1 = sum2;
            sum2 = x;
        }
        if(sum1 > 1)
            printf("Pair #%lld: All you need is love!\n", cnt);
        else
            printf("Pair #%lld: Love is not all you need!\n", cnt);
    }
    return 0;
}
