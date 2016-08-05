#include <cstdio>
#include <cstring>
#include <cmath>

long long phi[4000010], ans[4000010], f[4000010];

void phi_(void)
{
    long long i, j;
    for(i = 2; i < 4000002; ++i)
        phi[i] = i;

    for(i = 2; i < 4000002; ++i)
    {
        if(phi[i] == i)
            for(j = i; j < 4000002; j += i)
                phi[j] -= phi[j] / i;
    }

    for(i = 1; i < 4000002; ++i)
        for(j = i * 2; j < 4000002; j += i)
            f[j] += i * phi[j/i];

    ans[2] = 1;

    for(i = 3; i < 4000002; ++i)
        ans[i] = ans[i - 1] + f[i];
}

int main()
{
    long long a;
    phi_();
    while(scanf("%lld", &a) == 1)
    {
        if(a== 0)
            break;
        printf("%lld\n", ans[a]);
    }
    return 0;
}

