#include <cstdio>
long long arr[1000010];
long long ans[1000010];
long long func (long long x)
{
    if(arr[x] > 0)
        return arr[x];
    else
        return arr[x] = x * (x + 1) / 2;
}

int main()
{
    long long sum, i, j, x, n, det;
    while(scanf("%lld", &n) == 1)
    {
        if(n < 3)
            break;
        if(ans[n] > 0)
        {
            printf("%lld\n", ans[n]);
        }
        else
        {
            sum = 0;
            i = 2;
            j = n - 1;
            det = 0;
            x = j - i - det;
            while(x > 0)
            {
                sum += func(x);
                ++i;
                ++det;
                x = j - i - det;
            }
            printf("%lld\n", sum);
        }
    }
    return 0;
}
