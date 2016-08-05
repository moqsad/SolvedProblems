#include "bits/stdc++.h"
using namespace std;

#define PI 2 * acos(0)

int main()
{
    double a, b, c, k, in, out, mid, x;
    while(scanf("%lf %lf %lf", &a, &b, &c) == 3)
    {
        printf("%lf\n", PI);
        k = (a + b + c) / 2;
        mid = sqrt(k * (k - a) * (k - b) * (k - c));
        x = mid / k;
        in = x * x * PI;
        x = a * b * c;
        out = x * x  / ((a + b + c) * (b + c - a) * (c + a - b) * (a + b - c)) * PI - mid;
        printf("%.4lf %.4lf %.4lf\n", out, mid - in, in);
    }
    return 0;
}
