#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    int r;
    while(y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    int sum, total, x, n, i, cnt, t, y;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        sum = 0;
        total = 0;
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &x);
            sum += abs(x);
            if(x > 0)
                ++total;
        }
        if(total == 0)
            printf("Case %d: inf\n", cnt);
        else
        {
            y = gcd(sum, total);
            printf("Case %d: %d/%d\n", cnt, sum / y, total / y);
        }
    }
    return 0;
}
