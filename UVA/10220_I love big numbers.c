#include <stdio.h>

int num[1050];

int main()
{
    int a, cnt, i, ans[2800], j, x, y, tag;
    i = 1;
    num[0] = 1;
    ans[0] = 1;
    for(cnt = 1; cnt <= 1000; ++cnt)
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
        for(j = 0; j < i; ++j)
            num[cnt] += ans[j];
    }
    while(scanf("%d", &a) == 1)
    {
            printf("%d\n", num[a]);
    }
    return 0;
}

