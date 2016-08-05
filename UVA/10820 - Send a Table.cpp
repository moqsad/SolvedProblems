#include <cstdio>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

int arr[50005], prime[60], ans[50005];

void func(void)
{
    int cnt = 0, i, j, k;
    prime[cnt++] = 2;
    for(i = 3; i < 231; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 50001; j += k)
                arr[j] = 1;
        }
    }
    for(i = 4; i < 50001; i += 2)
        arr[i] = 1;
}

void precalculate(void)
{
    int i, j, x, y, z, cnt;
    ans[1] = 1;
    for(i = 2; i <= 50000; ++i)
    {
        cnt = 0;
        y = i;
        x = sqrt(i) + 2;
        z = 1;
        if(arr[y] == 0)
            z = y - 1;
        else
            while(prime[cnt] < x)
            {
                if(y % prime[cnt] == 0)
                {
                    j = 1;
                    y /= prime[cnt];
                    while(y % prime[cnt] == 0)
                    {
                        j *= prime[cnt];
                        y /= prime[cnt];
                    }
                    z *= j * (prime[cnt] - 1);
                    if(arr[y] == 0 && y > 1)
                    {
                        z *= (y - 1);
                        break;
                    }
                }
                ++cnt;
            }

        ans[i] = ans[i - 1] + 2 * z;
    }
}


int main()
{
    int n;
    func();
    precalculate();
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        printf("%d\n", ans[n]);
    }
    return 0;
}
