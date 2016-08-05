#include <stdio.h>
int main()
{
    long long int a, b, p, x, c, cnt = 0;
    while(1)
    {
        scanf("%lld %lld", &a, &b);
        c = a;
        if(a < 0 && b < 0)
            break;
        ++cnt;
        p = 0;
        x = 0;
        while(a > 1)
        {
            if(a % 2 == 1)
                a = 3 * a + 1;
            else
                a /= 2;
            ++x;
            if(a > b)
            {
                p = 1;
                break;
            }
        }
        if(p == 1)
            printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", cnt, c, b, x);
        else
            printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", cnt, c, b, ++x);
    }
    return 0;
}
