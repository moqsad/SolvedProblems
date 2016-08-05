#include <cstdio>

int main()
{
    int t, cnt, i, n, x1, y1, z1, x2, y2, z2, a1, b1, c1, a2, b2, c2, p, vari;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
        p = 0;
        for(i = 1; i < n; ++i)
        {
            scanf("%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2);

            vari = (a1 > x1) ? a1 : x1;
            if(a1 >= x1 && a1 <= x2)
                x1 = a1;
            else if(!(x1 >= a1 && x1 <= a2))
            {
                p = 1;
//                break;
            }

            if(a2 >= x1 && a2 <= x2)
                x2 = a2;
            else if(!(x2 >= a1 && x2 <= a2))
            {
                p = 1;
//                break;
            }

            if(b1 >= y1 && b1 <= y2)
                y1 = b1;
            else if(!(y1 >= b1 && y1 <= b2))
            {
                p = 1;
//                break;
            }

            if(b2 >= y1 && b2 <= y2)
                y2 = b2;
            else if(!(y2 >= b1 && y2 <= b2))
            {
                p = 1;
//                break;
            }

            if(c1 >= z1 && c1 <= z2)
                z1 = c1;
            else if(!(z1 >= c1 && z1 <= c2))
            {
                p = 1;
//                break;
            }

            if(c2 >= z1 && c2 <= z2)
                z2 = c2;
            else if(!(z2 >= c1 && z2 <= c2))
            {
                p = 1;
//                break;
            }
        }
        if(p==0)
            printf("Case %d: %d\n", cnt, (x2 - x1) * (y2 - y1) * (z2 - z1));
        else
            printf("Case %d: 0\n", cnt);
    }
    return 0;
}
