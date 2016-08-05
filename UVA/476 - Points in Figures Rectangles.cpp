#include <cstdio>
#include <iostream>
using namespace std;

double x1[20], y1[20], x2[20], y2[20];

int main()
{
    int i = 1, j, k = 0, p;
    double x, y;
    char ch;
    while(1)
    {
        scanf(" %c", &ch);
        if(ch == '*')
            break;
        scanf("%lf %lf %lf %lf", &x2[i], &y2[i], &x1[i], &y1[i]);
        ++i;
    }

    while(1)
    {
        scanf("%lf %lf", &x, &y);
        if(x == 9999.9 && y == 9999.9)
            break;
        ++k;
        p = 0;
        for(j = 1; j < i; ++j)
        {
            if(x < x1[j] && x > x2[j] && y > y1[j] && y < y2[j])
            {
                p = 1;
                printf("Point %d is contained in figure %d\n", k, j);
            }
        }
        if(p == 0)
            printf("Point %d is not contained in any figure\n", k);
    }
    return 0;
}
