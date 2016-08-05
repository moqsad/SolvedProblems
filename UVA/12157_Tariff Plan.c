#include <stdio.h>
int main()
{
    int t, n, arr, count, i, x, a, b;
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%d", &n);
        a = 0;
        b = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &arr);
            x = arr;
            while(1)
            {
                if(x >= 29)
                {
                    x -= 29;
                    ++a;
                }
                else
                {
                    ++a;
                    break;
                }
                a += x / 30;
                if(x % 30 > 0)
                    ++a;
                    break;
            }
            x = arr;
            while(1)
            {
                if(x >= 59)
                {
                    x -= 59;
                    ++b;
                }
                else
                {
                    ++b;
                    break;
                }
                b += x / 60;
                if(x % 60 > 0)
                    ++b;
                    break;
            }
        }
        a *= 10;
        b *= 15;
        if(a < b)
            printf("Case %d: Mile %d\n", count, a);
        else if(b < a)
            printf("Case %d: Juice %d\n", count, b);
        else
            printf("Case %d: Mile Juice %d\n", count, a);
    }
    return 0;
}
