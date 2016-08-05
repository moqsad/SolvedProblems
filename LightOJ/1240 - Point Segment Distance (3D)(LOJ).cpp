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

int main()
{
    int t, cnt, i;
    double x1, y1, z1, x2, y2, z2, x, y, z, tempx1, tempy1, tempz1, tempx2, tempy2, tempz2, s1, s2;

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &z1, &x2, &y2, &z2, &x, &y, &z);

        for(i = 0; i < 50; ++i)
        {
            tempx1 = (2.0 * x1 + 1.0 * x2) / 3.0;
            tempx2 = (1.0 * x1 + 2.0 * x2) / 3.0;
            tempy1 = (2.0 * y1 + 1.0 * y2) / 3.0;
            tempy2 = (1.0 * y1 + 2.0 * y2) / 3.0;
            tempz1 = (2.0 * z1 + 1.0 * z2) / 3.0;
            tempz2 = (1.0 * z1 + 2.0 * z2) / 3.0;

            s1 = sqrt((tempx1 - x) * (tempx1 - x) + (tempy1 - y) * (tempy1 - y) + (tempz1 - z) * (tempz1 - z));
            s2 = sqrt((tempx2 - x) * (tempx2 - x) + (tempy2 - y) * (tempy2 - y) + (tempz2 - z) * (tempz2 - z));

            if(s1 > s2)
            {
                x1 = tempx1;
                y1 = tempy1;
                z1 = tempz1;
            }
            else
            {
                x2 = tempx2;
                y2 = tempy2;
                z2 = tempz2;
            }
        }

        printf("Case %d: %.8lf\n", cnt, s1);
    }

    return 0;
}
