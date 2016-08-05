#include <stdio.h>
int main()
{
    long long int b, s, count = 0;
    while(1)
    {
        scanf("%lld %lld", &b, &s);
        if(b == 0 && s == 0)
            break;
        ++count;
        if(b == 1)
            printf("Case %lld: :-\\\n", count);
        else if(s >= b)
                printf("Case %lld: :-|\n", count);
        else if(s < b)
            printf("Case %lld: :-(\n", count);
    }
    return 0;
}
