#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, count, a, b;
    double x, y;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%d %d", &a, &b);
        if(a < b)
        printf("impossible\n");
        else
        {
            x = a;
            y = b;
            if((a + b) / 2 != (x + y) / 2 || (a - b) / 2 != (x - y) / 2)
            printf("impossible\n");
            else
            printf("%d %d\n", (a + b) / 2, abs((a - b) / 2));
        }
    }
    return 0;
}
