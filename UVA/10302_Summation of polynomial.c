#include <stdio.h>
int main()
{
    long long int a;
    while(scanf("%lld", &a) == 1)
    {
        printf("%lld\n", (a + 1) * a * a * (a + 1) / 4);
    }
    return 0;
}
