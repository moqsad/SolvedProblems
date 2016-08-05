#include <cstdio>

int num[100100];

int main()
{
    int i, ans, x, y, t, n, cnt;
    for(i = 1; i < 100001; ++i)
    {
        ans = y = i;
        while(y > 0)
        {
            ans += y % 10;
            y /= 10;
        }
        if(num[ans] == 0)
            num[ans] = i;
    }

    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d", &n);
        printf("%d\n", num[n]);
    }
    return 0;
}
