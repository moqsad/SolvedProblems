#include "bits/stdc++.h"
using namespace std;

int main()
{
    int t, h, m, cnt, i, x, n, h2, m2, minimum, a;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        scanf("%d:%d", &h, &m);
        minimum = 999999999;
        for(i = 0; i < n; ++i)
        {
            scanf("%d:%d %d", &h2, &m2, &a);
            if(h2 > h || (h2 == h && m2 >= m))
            {
                x = h2 * 60 + m2 + a - h * 60 - m;
                if(x < minimum)
                    minimum = x;
            }
            else
            {
                x = h2 * 60 + m2 + a - h * 60 - m + 1440;
                if(x < minimum)
                    minimum = x;
            }
        }
        printf("Case %d: %d\n", cnt, minimum);
    }
    return 0;
}
