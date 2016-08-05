#include <cstdio>
#include <cmath>

bool arr[1000020];
int ans[1000020], num[1000020];

int main()
{
    int cnt = 0, i, j, k, x, y, n, prime[210];
    prime[cnt++] = 2;
    for(i = 4; i < 1000010; i += 2)
        arr[i] = 1;
    for(i = 3; i < 1010; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 1000010; j += k)
                arr[j] = 1;
        }
    }

    for(i = 2; i < 1000010; ++i)
    {
        if(arr[i] == 0)
            num[i] = 1;
        else
        {
            y = i;
            cnt = 0;
            while(1)
            {
                if(y % prime[cnt] == 0)
                {
                    y /= prime[cnt];
                    ++num[i];
                    num[i] += num[y];
                    break;
                }
                ++cnt;
            }
        }
        ans[i] = ans[i - 1] + num[i];
    }

    while(scanf("%d", &n) == 1)
    {
        printf("%d\n", ans[n]);
    }
    return 0;
}
