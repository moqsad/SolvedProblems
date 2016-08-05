#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

#define PI acos(-1)

int main()
{
    int cnt, t;
    double x1, x2, y1, y2, R, r, X, Y, a, A, area1, area2;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &R, &x2, &y2, &r);

        A = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

        if(R + r <= A)
            printf("Case %d: 0\n", cnt);

        else if(A - r >= - R && A + r <= R)
            printf("Case %d: %.8lf\n", cnt, PI * r * r);

        else if(A - r <= - R && A + r >= R)
            printf("Case %d: %.8lf\n", cnt, PI * R * R);

        else
        {
            X = (R * R - r * r + A * A) / 2 / A;
            Y = sqrt(R * R - X * X);
            a = 2 * Y;

            if(X < 0)
            {
                area1 = R * R * asin(Y / R) - .5 * (-X) * a;
                area1 = PI * R * R - area1;
            }
            else
                area1 = R * R * asin(Y / R) - .5 * X * a;

            if(X > A)
            {
                area2 = r * r * asin(Y / r) - .5 * (X - A) * a;
                area2 = PI * r * r - area2;
            }
            else
                area2 = r * r * asin(Y / r) - .5 * (A - X) * a;

            printf("Case %d: %.8lf\n", cnt, area1 + area2);
        }
    }
    return 0;
}
