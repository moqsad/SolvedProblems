#include <stdio.h>
int main()
{
    long long int t, n, count, x, y, sum, i, z;
    scanf("%lld", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%lld", &n);
        if(n == 1)
            printf("Scenario #%lld:\n2\n\n", count);
        else if(n == 2)
            printf("Scenario #%lld:\n3\n\n", count);
        else
        {
        x = 0;
        y = 1;
        z = 2;
        for(i = 3; i <= n; ++i)
        {
            sum = x + y;
            y = z + x;
            x = sum;
            z *= 2;
        }
        printf("Scenario #%lld:\n%lld\n\n", count, z * 2 - (x + y));
        }
    }
    return 0;
}
