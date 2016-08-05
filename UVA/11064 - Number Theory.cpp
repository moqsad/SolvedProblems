#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

long long arr[46355], prime[5000];

void func(void)
{
    long long cnt = 0, i, j, k;
    prime[cnt++] = 2;
    for(i = 3; i < 46350; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
//            printf("%d____\n", prime[cnt-1]);
            k = i + i;
            for(j = i * i; j < 46350; j += k)
                arr[j] = 1;
        }
    }
}

int main()
{
    long long n, x, i, j, y, z, ans, cnt;
    func();
    while(scanf("%lld", &n) == 1)
    {
        ans = n;
        x = sqrt(n) + 2;
        cnt = 0;

        y = 1;
        z = 1;

        while(prime[cnt] < x)
        {
            if(n % prime[cnt] == 0)
            {
                n /= prime[cnt];
                i = 2;
                j = 1;
                while(n % prime[cnt] == 0)
                {
                    n /= prime[cnt];
                    ++i;
                    j *= prime[cnt];
                }
                y *= i;
                z *= (prime[cnt] - 1) * j;
            }
            ++cnt;
        }

        if(n > 1)
        {
            y *= 2;
            z *= (n - 1);
        }

        printf("%lld\n", ans - y - z + 1);
    }
    return 0;
}
