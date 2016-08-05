#include <cstdio>
long long prime[665000];
bool arr[10000010];

int main()
{
    long long i, j, cnt = 0, ans, k, n, x, a, t;
    prime[cnt++] = 2;
    for(i = 4; i <= 10000000; i += 2)
        arr[i] = 1;
    for(i = 3; i < 10000010; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 10000010; j += k)
            {
                arr[j] = 1;
            }
        }
    }
//    printf("%lld", cnt);
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);
        ans = 0;
        x = n / 2;
        i = 0;
        while(prime[i] <= x)
        {
            a = n - prime[i];
            if(arr[a] == 0)
                ++ans;
            ++i;
        }
        printf("Case %lld: %lld\n", cnt, ans);
    }
    return 0;
}
