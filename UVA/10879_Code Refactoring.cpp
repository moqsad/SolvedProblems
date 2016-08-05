#include <cstdio>
#include <cmath>

int main()
{
    int n, i, j, cnt, a, b;
    scanf("%d", &n);
    for(cnt = 1; cnt <= n; ++cnt)
    {
        scanf("%d", &a);
        b = sqrt(a) + 2;
        j = 0;
        printf("Case #%d: %d", cnt, a);
        for(i = 2; i < b; ++i)
        {
            if(a % i == 0)
            {
                printf(" = %d * %d", i, a / i);
                ++j;
                if(j == 2)
                    break;
            }
        }
        printf("\n");
    }
    return 0;
}
