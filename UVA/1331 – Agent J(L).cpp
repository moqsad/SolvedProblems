#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
   int t, cnt;
   double r1, r2, r3, area, a, b, c, angleA, angleB, angleC, x, y, z, s, q;
   scanf("%d", &t);
   for(cnt = 1; cnt <= t; ++cnt)
   {
       scanf("%lf %lf %lf", &r1, &r2, &r3);
       a = r2 + r3;
       b = r1 + r3;
       c = r1 + r2;
       angleA = acos((b * b + c * c - a * a) / (2 * b * c));
       angleB = acos((a * a + c * c - b * b) / (2 * a * c));
       angleC = acos((a * a + b * b - c * c) / (2 * a * b));
       x = r1 * r1 / 2 * angleA;
       y = r2 * r2 / 2 * angleB;
       z = r3 * r3 / 2 * angleC;
       s = (a + b + c) / 2;
       q = sqrt(s * (s - a) * (s - b) * (s - c));
       area = q - x - y- z;
       printf("Case %d: %.7lf\n", cnt, area);
   }
   return 0;
}
