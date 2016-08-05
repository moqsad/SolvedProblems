#include <stdio.h>
int main()
{
    int n, l, w, h, count;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%d %d %d", &l, &w, &h);
        if(l > 20 || w > 20 || h > 20)
        printf("Case %d: bad\n", count);
        else
        printf("Case %d: good\n", count);
    }
    return 0;
}
