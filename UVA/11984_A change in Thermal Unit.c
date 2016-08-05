#include <stdio.h>
int main()
{
    int a, b, count, n;
    float cel, inc, ans;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%d %d", &a, &b);
        cel = a, inc = b;
        ans = (inc * 5 + 9 * cel) / 9;
        printf("Case %d: %.2f\n", count, ans);
    }
    return 0;
}
