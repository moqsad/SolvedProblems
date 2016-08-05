#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, ans;
    while(1)
    {
        scanf("%d %d", &a, &b);
        if(a == -1 && b == -1)
        break;
        ans = abs(a - b);
        if(ans > 50)
        ans = 99 - ans + 1;
        printf("%d\n", ans);
    }
    return 0;
}
