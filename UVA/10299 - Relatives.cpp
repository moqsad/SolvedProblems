#include <cstdio>
#include <cmath>
#include <cstring>

bool arr[32000];
int prime[3500];

int func(int a, int i)
{
    int j, value = 1;
    for(j = 1; j <= i; ++j)
        value *= a;
    return value;
}

int main()
{
    int i, cnt = 0, j, k, n, x, y, ans;
    prime[cnt++] = 2;
    for(i = 3; i < 32000; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 32000; j += k)
                arr[j] = 1;
        }
    }
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        y = n;
        ans = 1;
        x = sqrt(n) + 2;
        cnt = 0;
        while(prime[cnt] < x)
        {
            i = 0;
            if(n % prime[cnt] == 0)
            {
                while(n % prime[cnt] == 0)
                {
                    n /= prime[cnt];
                    ++i;
                }
                ans = ans * (prime[cnt] - 1) * func(prime[cnt], (i - 1));
                x = sqrt(n) + 2;
            }
            ++cnt;
        }
        if(n > 1)
            ans = ans * (n - 1);
        if(y > 1)
            printf("%d\n", ans);
        else
            printf("0\n");
    }
    return 0;
}

