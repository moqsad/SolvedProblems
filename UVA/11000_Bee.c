#include <stdio.h>
int main()
{
    long long int n, count, fe, m, temp;
    while(1)
    {
        scanf("%lld", &n);
        if(n < 0)
        break;
        fe = 1;
        m = 0;
        for(count = 1; count <= n; ++count)
        {
            temp = m;
            m += fe;
            fe = 1 + temp;
        }
        printf("%lld %lld\n", m, m + fe);
    }
    return 0;
}
