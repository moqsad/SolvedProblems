#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{
    int cnt, t, x1, x2, a1, a2, y1, y2, b1, b2, strong, weak, unsecure, area;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d %d %d %d", &a1, &b1, &a2, &b2);

        area = abs(y2 - y1) * abs(x2 - x1) + abs(b2 -  b1) * abs(a2 - a1);


        if(a1 > x1)
            x1 = a1;
        if(b1 > y1)
            y1 = b1;
        if(a2 < x2)
            x2 = a2;
        if(b2 < y2)
            y2 = b2;

        if(x2 <= x1 || y2 <= y1)
            strong = 0;
        else
            strong = abs(y2 - y1) * abs(x2 - x1);

        unsecure = 10000 - area + strong;

        weak = area - strong - strong;


        printf("Night %d: %d %d %d\n", cnt, strong, weak, unsecure);
    }
    return 0;
}
