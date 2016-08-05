#include <stdio.h>
int main()
{
    int n, a, b, c, ans, count;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%d %d %d", &a, &b, &c);
        ans = (a >= b && a <= c) || ((a >= c && a <= b)) ? a :
        (b >= a && b <= c) || (b >= c && b <= a) ? b : c;
        printf("Case %d: %d\n", count, ans);
    }
    return 0;
}
