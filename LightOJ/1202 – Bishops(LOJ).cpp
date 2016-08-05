#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int r1, r2, c1, c2, x, y, cnt, t;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        x = abs(r1 - r2);
        y = abs(c1 - c2);
        if(x == y)
            printf("Case %d: 1\n", cnt);
        else if(x % 2 == y % 2)
            printf("Case %d: 2\n", cnt);
        else
            printf("Case %d: impossible\n", cnt);
    }
    return 0;
}
