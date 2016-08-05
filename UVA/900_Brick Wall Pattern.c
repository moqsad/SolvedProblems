#include <stdio.h>
int main()
{
    long long int sum, a, count, x, y;
    while(1)
    {
        scanf("%lld", &a);
        if(a == 0)
        break;
        x = 0;
        y = 1;
        sum = 0;
        for(count = 1; count<= a; ++count)
        {
            sum = x + y;
            x = y;
            y = sum;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
