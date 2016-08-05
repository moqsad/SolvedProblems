#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long long ans[1010], a[60];

int main()
{
    long long t, cnt, n, k, i, j, l, m, x, y, z, total;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &n, &k);

        for(i = 1; i <= n; ++i)
            scanf("%lld", &a[i]);

        memset(ans, 0, sizeof(ans));
        ans[0] = 1;

        for(i = 1; i <= n; ++i)
        {
            scanf("%lld", &x);
            y = a[i];
            for(j = k - y; j >= 0; --j)
            {
                z = j;
                for(l = 0; l < x; ++l)
                {
                    z += y;
                    if(z > k)
                        break;
                    ans[z] = (ans[z] + ans[j]) % 100000007;
                }
            }
        }

        printf("Case %lld: %lld\n", cnt, ans[k]);
    }
    return 0;
}

