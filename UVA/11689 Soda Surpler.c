#include <stdio.h>
int main()
{
    int n, a, b, c, count, x, ans;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%d %d %d", &a, &b, &c);
        x = a + b;
        ans = 0;
        while(!(x >= 0 && x < c))
        {
            ans += x / c;
            x = x / c + x % c;
        }
        printf("%d\n", ans);
    }
    return 0;
}
