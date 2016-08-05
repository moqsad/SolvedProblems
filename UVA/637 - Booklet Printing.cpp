#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, cnt, i, j, k, x;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;

        x = n / 4;
        if(n % 4 > 0)
            x += 1;

        j = 1;
        k = x * 4;
        printf("Printing order for %d pages:\n", n);
        for(i = 1; i <= x; ++i)
        {
            printf("Sheet %d, front: ", i);
            if(k <= n)
                printf("%d, ", k);
            else
                printf("Blank, ");
            printf("%d\n", j);

            ++j;
            --k;
            if(j <= n)
            {
                printf("Sheet %d, back : ", i);
                printf("%d, ", j);
                if(k <= n)
                    printf("%d\n", k);
                else
                    printf("Blank\n");
            }
            ++j;
            --k;
        }
    }
    return 0;
}
