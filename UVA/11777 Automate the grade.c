#include <stdio.h>
int main()
{
    int n, a, b, c, d, e, f, g, x, y, ans, count;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &g);
        x = (e >= f && e >= g) ? e : (f >= g && f >= e) ? f : g;
        y = (e >= f && e <= g) || (e >= g && e <= f) ? e :
         (f >= e && f <= g) || (f >= g && f <= e) ? f : g;
         ans = a + b + c + d + (x + y) / 2;
         if(ans >= 90)
         printf("Case %d: A\n", count);
         else if(ans >= 80)
         printf("Case %d: B\n", count);
         else if(ans >= 70)
         printf("Case %d: C\n", count);
         else if(ans >= 60)
         printf("Case %d: D\n", count);
         else
         printf("Case %d: F\n", count);
    }
    return 0;
}
