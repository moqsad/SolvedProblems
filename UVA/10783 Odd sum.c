#include <stdio.h>
int main()
{
    int n, a, b, count, ans;
    float p;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%d %d", &a, &b);
        if(a % 2 == 0)
        a += 1;
        p = (b - a) / 2 + 1;
        ans = p / 2 * (2 * a + (p - 1) * 2);
        printf("Case %d: %d\n", count, ans);
    }
    return 0;
}
