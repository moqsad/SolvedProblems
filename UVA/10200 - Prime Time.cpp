#include <cstdio>
#include <cmath>

int arr[10010], ans[10010], prime[1500], det[10010];

int main()
{
    long long i, j, x, y, k, cnt = 0, p;
    double a, b;
    arr[2] = 5;
    prime[cnt++] = 2;
    for(i = 3; i < 10010; i += 2)
    {
        if(arr[i] == 0)
        {
            arr[i] = 5;
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 10010; j += k)
            {
                arr[j] = 1;
            }
        }
    }
    cnt = 0;
    for(i = 0; i < 10001; ++i)
    {
        x = i * i + i + 41;
        if(x < 10010)
        {
            if(arr[x] == 5)
            {
                ++cnt;
                det[i] = 1;
            }
        }
        else
        {
            y  = sqrt(x) + 2;
            j = 0;
            p = 0;
            while(prime[j] < y)
            {
                if(x % prime[j] == 0)
                {
                    p = 1;
                    break;
                }
                ++j;
            }
            if(p == 0)
            {
                ++cnt;
                det[i] = 1;
            }
        }
        ans[i] = cnt;
    }
    while(scanf("%lld %lld", &x, &y) == 2)
    {
        a = ans[y] - ans[x];
        if(det[x] == 1)
            a = a + 1;
        b = y - x + 1;
        printf("%.2lf\n", a / b * 100.0 + 1e-9);
    }
    return 0;
}
