#include <stdio.h>
#include <math.h>

int main()
{
    long long int n, x, y, i, cnt, p, q;
    while(1)
    {
        scanf("%lld", &n);
        if(n < 0)
            break;
            q = 0;
        y = ceil(sqrt(n));
        for(cnt = y; cnt > 1; --cnt)
        {
            x = n;
            p = 0;
            for(i = cnt; i > 0; --i)
            {
                if(x % cnt == 1)
                    x = x - (x - 1) / cnt - 1;
                else
                {
                    p = 1;
                    break;
                }
            }
            if(p == 0 && x % cnt == 0)
            {
                q = 1;
                break;
            }
        }
        if(q == 0)
            printf("%lld coconuts, no solution\n", n);
        else
            printf("%lld coconuts, %lld people and 1 monkey\n", n, cnt);
    }
    return 0;
}
