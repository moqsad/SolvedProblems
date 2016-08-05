#include <stdio.h>
int main()
{
    int n, count = 0;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        ++count;
        printf("Case %d: %d\n", count, n / 2);
    }
    return 0;
}
