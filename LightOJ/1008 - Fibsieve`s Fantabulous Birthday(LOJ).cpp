#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    long long t, cnt, n, x, m, z;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &x);
        n = (long long)ceil(sqrt(x));
        m = n - 1;
        z = x - m * m;
        if(n % 2 == 0)
        {
            if(z <= n)
                printf("Case %lld: %lld %lld\n", cnt, z, n);
            else
                printf("Case %lld: %lld %lld\n", cnt, n, n + n - z);
        }

        else
        {
            if(z <= n)
                printf("Case %lld: %lld %lld\n", cnt, n, z);
            else
                printf("Case %lld: %lld %lld\n", cnt, n + n - z, n);
        }
    }
    return 0;
}

