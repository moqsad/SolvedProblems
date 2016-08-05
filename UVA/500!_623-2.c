#include <stdio.h>
int main()
{
    int a, cnt, i, ans[2800], j, x, y, tag, num[1050];
    while(scanf("%d", &a) == 1)
    {
        i = 1;
        ans[0] = 1;
        for(cnt = 1; cnt <= a; ++cnt)
        {
            x = 0;
            tag = i;
            for(i = 0; i < tag; ++i)
            {
                y = ans[i] * cnt + x;
                ans[i] = y % 10;
                x = y / 10;
            }
            while(x != 0)
            {
                ans[i++] = x % 10;
                x /= 10;
            }
        }
        printf("%d!\n", a);
        for(cnt = i - 1; cnt >= 0; --cnt)
            printf("%d", ans[cnt]);
        printf("\n");
    }
    return 0;
}
