#include <stdio.h>
int main()
{
    long long int t, count, a, b;
    scanf("%lld", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%lld %lld", &a, &b);
        if(a == b)
            printf("=\n");
        else if(a > b)
            printf(">\n");
        else
            printf("<\n");
    }
    return 0;
}
