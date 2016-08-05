#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int arr[105][105], value[105][105];

int main()
{
    int n, i, j, k, l, x, y, total, sum;
    while(scanf("%d", &n) == 1)
    {
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
                scanf("%d", &arr[i][j]);

                total = 0;

        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
            {
                x = i;
                y = j;
                for(k = i; k <= n; ++k)
                    for(l = j; l <= n; ++l)
                    {
                        sum = 0;
                        if(k - 1 >= x)
                            sum += value[k - 1][l];
                        if(l - 1 >= y)
                            sum += value[k][l - 1];
                        if(k - 1 >= x && l - 1 >= y)
                            sum -= value[k -  1][l - 1];
                        value[k][l] = sum + arr[k][l];
                        if(value[k][l] > total)
                            total = value[k][l];
                    }
            }
            printf("%d\n", total);
    }
    return 0;
}
