#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

long long func(long long a, long long b)
{
    long long x = a - b;
    if(x > 0)
        return x;
    return - x;
}

int main()
{
    long long t, cnt, Ax, Ay, Bx, By, x, y, z, max_, i, w;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld %lld %lld", &Ax, &Ay, &Bx, &By);

        x = func(Ax, Bx);
        y = func(Ay, By);

        z = sqrt(x) + 2;

        if(x == 0)
            printf("Case %lld: %lld\n", cnt, y + 1);
        else
        {
//            multi = (double)y / (double)x;

            max_ = 0;

            for(i = 1; i < z; ++i)
            {
                if(x % i == 0)
                {
                    w = i % x;
                    if((w * y) % x == 0)
                        max_ = max(x / i, max_);

                    w = (x / i) % x;
                    if((w * y) % x == 0)
                        max_ = max(i, max_);
                }
            }

            if(max_ > 0)
                printf("Case %lld: %lld\n", cnt, max_ + 1);
            else
                printf("Case %lld: 2\n", cnt);
        }
    }
    return 0;
}
