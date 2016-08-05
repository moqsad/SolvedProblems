#include <stdio.h>
#include <math.h>
int main()
{
    long long int n, count, arr[12], x, k, y, sum, p, i, m, z, det;
    scanf("%lld", &n);
    for(m = 1; m <= n; ++m)
    {
        scanf("%lld", &x);
        z = x;
        count = 0;
        while(x != 0)
        {
            arr[count] = x % 10;
            x /= 10;
            ++count;
        }
        k = count - 1;
        y = 0;
        i = k;
        for(count = 0; count <= k; ++count)
        {
            y += arr[count] * pow(10.0, (double)i);
            --i;
        }
        x = z;
        sum = x + y;
        z = sum;
        count = 0;
        while(sum != 0)
        {
            arr[count] = sum % 10;
            sum /= 10;
            ++count;
        }
        sum = z;
        k = count - 1;
        i = k;
        p = 1;
        for(count = 0; count <= k / 2; ++count)
        {
            if(arr[count] != arr[i])
            {
                p = 0;
                break;
            }
            --i;
        }
        det = 1;
        while(p == 0)
        {
            y = 0;
            x = sum;
            z = x;
            count = 0;
            while(x != 0)
            {
                arr[count] = x % 10;
                x /= 10;
                ++count;
            }
            k = count - 1;
            i = k;
            for(count = 0; count <= k; ++count)
            {
                y += ceil(arr[count] * pow(10.0, (double)i));
                --i;
            }
            x = z;
            sum = x + y;
            z = sum;
            count = 0;
            while(sum != 0)
            {
                arr[count] = sum % 10;
                sum /= 10;
                ++count;
            }
            sum = z;
            k = count - 1;
            i = k;
            p = 1;
            for(count = 0; count <= k / 2; ++count)
            {
                if(arr[count] != arr[i])
                {
                    p = 0;
                    break;
                }
                --i;
            }
            ++det;
        }
        printf("%lld %lld\n", det, sum);
    }
    return 0;
}
