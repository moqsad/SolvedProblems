#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, t, count;
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%d", &n);
        n = n * 315 + 7492 * 5 - 498;
        n = abs(n / 10);
        printf("%d\n", n % 10);
    }
    return 0;
}
