#include <stdio.h>
int main()
{
    int n, a, b, c, x, y, z, count;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%d %d %d", &a, &b, &c);
        x = (a >= b && a >= c) ? a :(b >= c && b >= a) ? b : c;
        y = (a >= b && a <= c) || (a >= c && a <= b) ? a :
        (b >= c && b <= a) || (b >= a && b <= c) ? b : c;
        z = (a <= b && a <= c) ? a :(b <= c && b <= a) ? b : c;
        if(x >= y + z)
        printf("Wrong!!\n");
        else
        printf("OK\n");
    }
    return 0;
}
