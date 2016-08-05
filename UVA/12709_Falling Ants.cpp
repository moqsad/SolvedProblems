#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int ans, a, b, c, i, cnt, x, t, total;
    while(scanf("%d", &t) == 1)
    {
        if(t == 0)
            break;
        total = 0;
        for(cnt = 0; cnt < t; ++cnt)
        {
            scanf("%d %d %d", &a, &b, &c);
            if(c > total)
            {
                ans = a * b * c;
                total = c;
            }
            else if(c == total)
            {
                x = a * b * c;
                ans = (ans > x) ? ans : x;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
