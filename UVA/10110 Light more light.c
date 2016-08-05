#include <stdio.h>
#include <math.h>
int main()
{
    long long int n, count, i;
    double k;
    while(1)
    {
        scanf("%lld", &n);
        if(n == 0)
            break;
            k = n;
        if(sqrt(k) == (int)sqrt(k))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
