#include <stdio.h>
int main()
{
    long long int a, x, y, ans, count;
    while(1)
    {
        scanf("%lld", &a);
        if(a == 0)
        break;
        if(a == 1)
        printf("1\n");
        else if(a == 2)
        printf("2\n");
        else
        {
            x = 1;
            y = 2;
            for(count = 3; count <= a; ++count)
            {
                ans = x + y;
                x = y;
                y = ans;
            }
        printf("%lld\n", ans);
        }
    }
    return 0;
}
