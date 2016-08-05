#include <cstdio>

int arr[1000010];
int prime[80000];

int main()
{
    long long  i, j, k, x, y, n, cnt = 0, p;
    prime[cnt++] = 2;
    arr[2] = 5;
    for(i = 3; i < 1000010; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            arr[i] = 5;
            for(j = i * i; j < 1000010; j += k)
            {
                arr[j] = 1;
            }
        }
    }
    while(scanf("%lld", &n) == 1)
    {
        if(n == 0)
            break;
        printf("%d:\n", n);
        p = 0;
        i = 0;
        x = n / 2;
        while(prime[i] <= x)
        {
            y = n - prime[i];
            if(arr[y] == 5)
            {
                p = 1;
                printf("%d+%d\n", prime[i], y);
                break;
            }
            ++i;
        }
        if(p == 0)
            printf("NO WAY!\n");
    }
    return 0;
}
