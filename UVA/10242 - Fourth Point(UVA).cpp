#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4, ansx, ansy;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4) == 8)
    {
        if(x1 == x3 && y1 == y3)
        {
            ansx = x2 + x4 - x1;
            ansy = y2 + y4 - y1;
        }
        else if(x1 == x4 && y1 == y4)
        {
            ansx = x2 + x3 - x1;
            ansy = y2 + y3 - y1;
        }
        else if(x2 == x4 && y2 == y4)
        {
            ansx = x1 + x3 - x2;
            ansy = y1 + y3 - y2;
        }
        else
        {
            ansx = x1 + x4 - x2;
            ansy = y1 + y4 - y2;
        }
        printf("%.3lf %.3lf\n", ansx, ansy);
    }
    return 0;
}
