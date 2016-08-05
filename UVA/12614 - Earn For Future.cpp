#include <cstdio>

int main()
{
    int cnt, i, t, n, a, big;
    scanf("%d", &t);
    ++t;
    for(cnt = 1; cnt < t; ++cnt)
    {
        scanf("%d", &n);
        big = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            if(a > big)
                big = a;
        }
        printf("Case %d: %d\n", cnt, big);
    }
    return 0;
}
