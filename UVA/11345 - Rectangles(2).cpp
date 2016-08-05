#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int t, cnt, n, i, j, x1, x2, y1, y2, a1, a2, b1, b2, p;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        p = 1;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for(i = 1; i < n; ++i)
        {
            scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
            if(a1 >= x1 && a1 <= x2 && b1 >= y1 && b1 <= y2)
            {
                x1 = a1;
                y1 = b1;
            }

            else if(a1 >= x1 && a1 <= x2 && y1 >= b1 && y1 <= b2)
            {
                x1 = a1;
            }

            else if(x1 >= a1 && x1 <= a2 && b1 >= y1 && b1 <= y2)
            {
                y1 = b1;
            }

            else if(!(x1 >= a1 && x1 <= a2 && y1 >= b1 && y1 <= b2))
            {
                p = 0;
                break;
            }


            if(a2 >= x1 && a2 <= x2 && b2 >= y1 && b2 <= y2)
            {
                x2 = a2;
                y2 = b2;
            }

            else if(a2 >= x1 && a2 <= x2 && y2 >= b1 && y2 <= b2)
            {
                x2 = a2;
            }

            else if(x2 >= a1 && x2 <= a2 && b2 >= y1 && b2 <= y2)
            {
                y2 = b2;
            }

            else if(!(x2 >= a1 && x2 <= a2 && y2 >= b1 && y2 <= b2))
            {
                p = 0;
                break;
            }
        }

        for(i = i + 1; i < n; ++i)
        {
            scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
        }
        if(p == 0)
            printf("Case %d: 0\n", cnt);
        else
            printf("Case %d: %d\n", cnt, abs(x1 - x2) * abs(y1 - y2));
    }
    return 0;
}

