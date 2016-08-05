#include <stdio.h>
#include <math.h>
int main()
{
    int n, count, i, j, p, q, x, y, z;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        for(count = 3; count <= n / 2 + 1; count += 2)
        {
            x = sqrt(count) + 1;
            p = 1;
            for(i = 2; i <= x; ++i)
            {
                if(count % i == 0)
                {
                    p = 0;
                    break;
                }
            }
            if(p == 1)
            {
                q = 1;
                z = n - count;
                y = sqrt(z) + 1;
                for(i = 2; i < y; ++i)
                {
                    if(z % i == 0)
                    {
                        q = 0;
                        break;
                    }
                }
                if(q == 1)
                {
                   printf("%d = %d + %d\n", n, count, z);
                   break;
                }
            }
        }
    }
    return 0;
}
