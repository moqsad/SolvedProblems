#include <stdio.h>
int main()
{
    int a, n, s, p, ans, count;
    scanf("%d", &a);
    for(count = 1; count <= a; ++count)
    {
        scanf("%d %d %d", &n, &s, &p);
        ans = s + p % n;
        if(ans > n)
        ans -= n;
        printf("Case %d: %d\n", count, ans);
    }
    return 0;
}
