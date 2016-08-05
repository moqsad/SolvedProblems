#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int t, n, i, cnt, x, y, z, ans;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        x = 2;
        ans = 0;
        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &y);
            if(y > x)
            {
                z = y - x;
                ans += z / 5;
                if(z % 5 > 0)
                    ++ans;
            }
            x = y;
        }
        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}
