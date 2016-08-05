#include <stdio.h>
int main()
{
    int r, l, w, l1, l2, t, count;
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%d", &r);
        l = r * 5;
        w = 6 * l / 10;
        w /= 2;
        l1 = 45 * l / 100;
        l2 = 55 * l / 100;
        printf("Case %d:\n", count);
        printf("%d %d\n", - l1, w);
        printf("%d %d\n", l2, w);
        printf("%d %d\n", l2, - w);
        printf("%d %d\n", - l1, - w);
    }
    return 0;
}
