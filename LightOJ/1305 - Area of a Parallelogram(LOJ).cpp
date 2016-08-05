#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    int t, cnt, Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    double x, y, z, angle, ans;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
        Dx = Cx - Bx + Ax;
        Dy = Cy - By + Ay;
        x = sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));
        y = sqrt((Ax - Dx) * (Ax - Dx) + (Ay - Dy) * (Ay - Dy));
        z = sqrt((Dx - Bx) * (Dx - Bx) + (Dy - By) * (Dy - By));
        angle = acos((x * x + y * y - z * z) / 2.0 / x / y);
        ans = y * sin(angle);
        printf("Case %d: %d %d %.0lf\n", cnt, Dx, Dy, ans * x);
    }
    return 0;
}
