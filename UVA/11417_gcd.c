#include <stdio.h>
int main()
{
    int ans, b, n, count, j;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        ans = 0;
        for(count = 1; count < n; ++count)
            for(b = count + 1; b <= n; ++b)
            {
                if(b % count == 0)
                    ans += count;
                else
                    for(j = count / 2; j >= 1; --j)
                        if(b % j == 0 && count % j == 0)
                        {
                            ans += j;
                            break;
                        }
            }
        printf("%d\n", ans);
    }
    return 0;
}
