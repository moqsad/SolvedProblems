#include <stdio.h>
#include <math.h>

long long int arr[90000];

int main()
{
    long long int n, i, j, x, cnt, p;
    arr[0] = 2;
    arr[1] = 3;
    j = 1;
    for(cnt = 5; cnt < 1000000; cnt += 2)
    {
        p = 0;
        x = sqrt(cnt) + 2;
        for(i = 2; i < x; ++i)
        {
            if(cnt % i == 0)
            {
                p = 1;
                break;
            }
        }
        if(p == 0)
            arr[++j] = cnt;
    }
    while(1)
    {
        scanf("%lld", &n);
        if(n < 0)
            break;
        i = 0;
        x = sqrt(n);
        while(1)
        {
            if(arr[i] > x || i > j)
                break;
            if(n % arr[i] == 0)
            {
                n /= arr[i];
                printf("    %lld\n", arr[i]);
                x = sqrt(n);
            }
            else
            {
                ++i;
            }
        }
        printf("    %lld\n\n", n);
    }
    return 0;
}
