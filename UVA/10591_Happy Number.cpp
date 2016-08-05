#include <stdio.h>
int main()
{
    long long int n, count, i, sum, x, det, arr[30], y, t, j;
    scanf("%lld", &t);
    for(det = 1; det <= t; ++det)
    {
        scanf("%lld", &n);
        sum = n;
        x = n;
        j = 0;
        while(1)
        {
            n = sum;
            sum = 0;
            i = 0;
            while(n != 0)
            {
                arr[i++] = n % 10;
                n /= 10;
            }
            for(count = 0; count < i; ++count)
            {
                sum += arr[count] * arr[count];
            }
            if(sum == 1)
            {
                printf("Case #%lld: %lld is a Happy number.\n", det, x);
                break;
            }
            if(sum == 4)
            {
                printf("Case #%lld: %lld is an Unhappy number.\n", det, x);
                break;
            }
        }
    }
    return 0;
}
