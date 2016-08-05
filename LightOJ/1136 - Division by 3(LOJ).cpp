#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int t, a, b, x, y, z, cnt;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &a, &b);
        x = b - a + 1;
        y = (x / 3) * 2;
        z = x % 3;
        if(z == 1)
        {
            if(a % 3 != 1)
                ++y;
        }

        else if(z == 2)
        {
            if(a % 3 == 2)
                y += 2;
            else
                ++y;
        }

        printf("Case %d: %d\n", cnt, y);
    }
    return 0;
}
