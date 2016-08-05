#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

#define PI acos(-1)

int main()
{
    int cnt, t;
    double Ox, Oy, Ax, Ay, Bx, By, angle, x, y, z;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &Ox, &Oy, &Ax, &Ay, &Bx, &By);
        y = sqrt((Ox - Bx) * (Ox - Bx) + (Oy - By) * (Oy - By));
        z = sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));
        angle = acos((2.0 * y * y - z * z) / 2.0 / y / y);
        x = angle * y;
        printf("Case %d: %.6lf\n", cnt, x);
    }
    return 0;
}
