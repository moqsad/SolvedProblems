#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long i, z, x, y, j, k, l, n, cnt, t;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld %lld", &x, &y, &n);
        z = sqrt(y);
        k = x;
        for(i = 1; i < z; ++i)
        {
            k = (k * (x % n)) % n;
        }

        l = k;
        j = z;
        z += z;
        while(z <= y)
        {
            k = (k * (l % n)) % n;
            z += j;
        }

        y = y - z + j;
        if(y > 0)
        {
            l = x;
            for(i = 1; i < y; ++i)
            {
                l = (l * (x % n)) % n;
            }
            printf("%lld\n", (k * l) % n);
        }

        else
            printf("%lld\n", k);
    }
    scanf("%lld", &x);
    return 0;
}

