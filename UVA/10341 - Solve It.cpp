#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int i;
    double p, q, r, s, t, u, a, b, c, mid;
    while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6)
    {

            a = p*exp(0) + r*cos(0);
            b = p*exp(-1)+ q*sin(1) + r*cos(1) + s*tan(1) + t;
//            printf("%lf %lf\n", a, b);
            if(-u >= b && -u <= a)
            {
                a = 0;
                b = 1;
                for(i = 0; i < 25; ++i)
                {
                    mid = (a + b) / 2;
                    c = p*exp(-mid)+ q*sin(mid) + r*cos(mid) + s*tan(mid) + t * mid * mid + u;

                    if(c > 0)
                        a = mid;

                    else if(c < 0)
                        b = mid;

                    else
                        break;
                }
                printf("%.4lf\n", mid);
            }
            else
                printf("No solution\n");
    }
    return 0;
}
