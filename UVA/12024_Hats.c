#include <stdio.h>
#include <math.h>

long long int arr[15];

int main()
{
    long long int cnt, n, fact[15], x = 1, i, y, t;
    for(cnt = 2; cnt < 13; ++cnt)
    {
        x *= cnt;
        fact[cnt] = x;
        y = cnt + 1;
        for(i = 2; i < y; ++i)
        {
            if(i % 2 == 0)
                arr[cnt] += fact[cnt] / fact[i];
            else
                arr[cnt] -= fact[cnt] / fact[i];
        }
    }
    scanf("%lld", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%lld", &n);
        printf("%lld/%lld\n", arr[n], fact[n]);
    }
    return 0;
}
