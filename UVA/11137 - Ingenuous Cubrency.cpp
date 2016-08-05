#include <cstdio>
#include <iostream>
using namespace std;

long long ans[10010];

int main()
{
    long long i, j, x, n;
    ans[0] = 1;
    for(i = 1; i < 22; ++i)
    {
        x = i * i * i;
        for(j = x; j < 10000; ++j)
            ans[j] = ans[j] + ans[j - x];
    }

    while(scanf("%lld", &n) == 1)
        printf("%lld\n", ans[n]);
    return 0;
}
