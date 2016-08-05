#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int cnt, t, n, k, x;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d", &k);
        if(cnt > 0)
            printf("\n");
        if(k == 0)
            printf("3\n");
        else
        {
            k = abs(k);
            n = ceil((-1 + sqrt(1 + 8 * (double)k)) / 2.0);
            x = n * (n + 1) / 2 - k;
            if(x % 2 == 0)
                printf("%d\n", n);
            else
            {
                if(n % 2 == 1)
                    printf("%d\n", n + 2);
                else
                    printf("%d\n", n + 1);
            }
        }
    }
    return 0;
}
