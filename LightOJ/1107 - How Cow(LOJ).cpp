#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int t, a, b, c, d, cnt, x, y, i, m;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        scanf("%d", &m);
        printf("Case %d:\n", cnt);
        for(i = 0; i <m; ++i)
        {
            scanf("%d %d", &x, &y);
            if(a < x && x < c && b < y && y < d)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
