#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int total, n, a, x, p, i;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;

        total = 0;
        x = 0;

        for(i = 0; i < n; ++i)
        {
            scanf("%d", &a);

            x += a;

            if(x < 0)
                x = 0;

            else if(x > total)
                total = x;
        }


        if(total > 0)
            printf("The maximum winning streak is %d.\n", total);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
