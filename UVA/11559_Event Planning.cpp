#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int n, b, h, w, p, a, cnt, i, j, x, y;
    while(scanf("%d %d %d %d", &n, &b, &h, &w) == 4)
    {
        y = 500010;
        for(cnt = 0; cnt < h; ++cnt)
        {
            scanf("%d", &p);
            for(i = 0; i < w; ++i)
            {
                scanf("%d", &a);
                if(a >= n)
                {
                    x = n * p;
                    if(x <= b && x < y)
                        y = x;
                }
            }
        }
        if(y < 500010)
            printf("%d\n", y);
        else
            printf("stay home\n");
    }
    return 0;
}
