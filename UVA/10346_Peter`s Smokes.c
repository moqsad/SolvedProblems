#include <stdio.h>
int main()
{
    int a, b, ans;
    while(scanf("%d %d", &a, &b) == 2)
    {
        ans = a;
        while(!(a >= 0 && a < b))
        {
            ans += a / b;
            a = a / b + a % b;
        }
        printf("%d\n", ans);
    }
    return 0;
}
