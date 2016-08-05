#include <stdio.h>
int main()
{
    long long int a, b, c, d, l, count, sum, i;
    while(1)
    {
        scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &l);
        if(a == 0 && b == 0 && c == 0 && d == 0 && l == 0)
            break;
        i = 0;
        for(count = 0; count <= l; ++count)
        {
            sum = a * count * count + b * count + c;
            if(sum % d == 0)
                ++i;
        }
        printf("%lld\n", i);
    }
    return 0;
}
