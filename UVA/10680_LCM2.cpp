#include <stdio.h>

long long int num[1000050], ans[1000050], arr[1000050];

int main()
{
    long long int prime[90000], i, j, k, l, cnt = 0, x, y, a;
    prime[cnt++] = 2;
    for(i = 3; i < 1000001; i += 2)
    {
        if(num[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 1000001; j += k)
            {
                num[j] = 1;
            }
        }
    }
    i = cnt;
    for(cnt = 0; cnt < i; ++cnt)
    {
        x = 1;
        x = x * prime[cnt];
        while(x < 1000001)
        {
            ans[x] = prime[cnt];
            x *= prime[cnt];
        }
    }

    x = 1;
    for(cnt = 1; cnt < 1000001; ++cnt)
    {
        if(ans[cnt] > 0)
        {
            x *= ans[cnt];
            while(x % 10 == 0)
                x /= 10;
            x = x % 1000000;
        }
        arr[cnt] = x;
    }
    while(scanf("%lld", &a) == 1)
    {
        if(a == 0)
            break;
        printf("%lld\n", arr[a] % 10);
    }
    return 0;
}
