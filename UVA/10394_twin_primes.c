#include <stdio.h>

long long int arr1[100050], arr2[100050], arr[20000050];

int main()
{
    long long int cnt, i, j, n, x, k;
    cnt = 0;
    x = 3;
    for(i = 3; i < 20000001; i += 2)
    {
        if(arr[i] == 0)
        {
            k = i + i;
            if(i - x == 2)
            {
                ++cnt;
                arr1[cnt] = x;
                arr2[cnt] = i;
            }
            for(j = i * i; j < 20000001; j += k)
            {
                arr[j] = 1;
            }
            x = i;
        }
        if(cnt == 100000)
            break;
    }
    while(scanf("%lld", &n) == 1)
    {
        printf("(%lld, %lld)\n", arr1[n], arr2[n])   ;
    }
    return 0;
}
