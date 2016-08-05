#include <stdio.h>
int main()
{
    int ans, a;
    while(scanf("%d", &a) == 1)
    {
        ans = a;
        while(!(a >= 0 && a < 3))
        {
            ans += a / 3;
            a = a / 3 + a % 3;
        }
        if(a == 2)
        ++ans;
        printf("%d\n", ans);
    }
    return 0;
}

