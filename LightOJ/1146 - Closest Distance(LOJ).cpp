#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <iostream>
using namespace std;

double dist(double sx, double sy, double ex, double ey)
{
    return sqrt((sx - ex) * (sx - ex) + (sy - ey) * (sy - ey));
}

int main()
{
    int t, cnt, i;
    double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy, tempx1_1, tempx1_2, tempy1_1, tempy1_2, tempx2, tempy2, v1, vx2, vy2;
    double temptime1_, temptime2_, temps1, temps2, s1, time_ = 50.0, pretime_;

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy);

        v1 = dist(Ax, Ay, Bx, By) / time_;
        vx2 = (Dx - Cx) / time_;
        vy2 = (Dy - Cy) / time_;
        pretime_ = 0;

        for(i = 0; i < 50; ++i)
        {
            tempx1_1 = (Ax * 2.0 + Bx * 1.0) / 3.0;
            tempy1_1 = (Ay * 2.0 + By * 1.0) / 3.0;
            s1 = dist(tempx1_1, tempy1_1, Ax, Ay);
            temptime1_ = pretime_ + s1 / v1;
            tempx2 = Cx + vx2 * temptime1_;
            tempy2 = Cy + vy2 * temptime1_;
            temps1 = dist(tempx1_1, tempy1_1, tempx2, tempy2);

            tempx1_2 = (Ax * 1.0 + Bx * 2.0) / 3.0;
            tempy1_2 = (Ay * 1.0 + By * 2.0) / 3.0;
            s1 = dist(tempx1_2, tempy1_2, Ax, Ay);
            temptime2_ = pretime_ + s1 / v1;
            tempx2 = Cx + vx2 * temptime2_;
            tempy2 = Cy + vy2 * temptime2_;
            temps2 = dist(tempx1_2, tempy1_2, tempx2, tempy2);

            if(temps1 > temps2)
            {
                pretime_ = temptime1_;
                Ax = tempx1_1;
                Ay = tempy1_1;
            }
            else
            {
                Bx = tempx1_2;
                By = tempy1_2;
            }
        }

        printf("Case %d: %.8lf\n", cnt, min(temps1, temps2));
    }
    return 0;
}
