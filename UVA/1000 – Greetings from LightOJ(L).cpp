#include <cstdio>

int main()
{
    int t, cnt, a, b;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", cnt, a + b);
    }
    return 0;
}
