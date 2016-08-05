#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long a[110], ans[11000];

int main()
{
    long long t, cnt, n, k, i, j;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &n, &k);
        for(i = 0; i < n; ++i)
            scanf("%lld", &a[i]);
        memset(ans, 0, sizeof(ans));
        ans[0] = 1;
        for(i = 0; i < n; ++i)
            for(j = a[i]; j <= k; ++j)
                ans[j] = (ans[j] + ans[j - a[i]]) % 100000007;
        printf("Case %lld: %lld\n", cnt, ans[k]);
    }
    return 0;
}
