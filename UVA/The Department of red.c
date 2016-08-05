#include <stdio.h>

long long int a[1000050], b[1000050], x;

int main()
{
    int cnt, i = 0, p;
    while(scanf("%lld", &x) == 1)
    {
        p = 0;
        for(cnt = 0; cnt < i; ++cnt)
        {
            if(a[cnt] == x)
            {
                p = 1;
                break;
            }
        }
        if(p == 0)
        {
            a[i] = x;
            ++b[i];
            ++i;
        }
        else
        {
            ++b[cnt];
        }
    }
    for(cnt = 0; cnt < i; ++cnt)
        printf("%lld %lld\n", a[cnt], b[cnt]);
    return 0;
}
