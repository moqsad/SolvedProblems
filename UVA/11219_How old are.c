#include <stdio.h>
int main()
{
    long long int t, count, ans, p, d1, d2, m1, m2, y1, y2;
    scanf("%lld", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%lld / %lld / %lld", &d1, &m1, &y1);
        scanf("%lld / %lld / %lld", &d2, &m2, &y2);
        while(1)
        {
            if(y1 > y2)
            {
                p = 1;
                if(m1 > m2)
                    ans = y1 - y2;
                else if(m1 == m2 && d1 >= d2)
                    ans = y1 - y2;
                else
                    ans = y1 - y2 - 1;
                if(p == 1)
                {
                    if(ans > 130)
                        printf("Case #%lld: Check birth date", count);
                    else
                        printf("Case #%lld: %lld", count, ans);
                }
            }
            else if(y1 < y2)
                printf("Case #%lld: Invalid birth date", count);
            else
            {
                if(m1 > m2)
                    printf("Case #%lld: 0", count);
                else if(m1 == m2 && d1 >= d2)
                    printf("Case #%lld: 0", count);
                else
                    printf("Case #%lld: Invalid birth date", count);
            }
            break;
        }
    }
    printf("\n");
    return 0;
}
