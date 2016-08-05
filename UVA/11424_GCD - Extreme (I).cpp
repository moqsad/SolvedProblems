#include <cstdio>
#include <cstring>
#include <cmath>

long long phi[200010], ans[200010], f[200010];

void phi_(void)
{
    long long i, j;
    for(i = 2; i < 200002; ++i)
        phi[i] = i;

    for(i = 2; i < 200002; ++i)
    {
        if(phi[i] == i)
            for(j = i; j < 200002; j += i)
                phi[j] -= phi[j] / i;
    }

    for(i = 1; i < 200002; ++i)
        for(j = i * 2; j < 200002; j += i)
            f[j] += i * phi[j/i];

    ans[2] = 1;

    for(i = 3; i < 200002; ++i)
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
