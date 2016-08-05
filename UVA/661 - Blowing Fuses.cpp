#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int arr[25], toggle[25];

int main()
{
    int n, m, c, i, max, x, sum, cnt = 0;
    while(scanf("%d %d %d", &n, &m, &c) == 3)
    {
        if(n == 0 && m == 0 && c == 0)
            break;

        for(i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);

        max = 0;
        sum = 0;

        memset(toggle, 0, sizeof(toggle));

        for(i = 0; i < m; ++i)
        {
            scanf("%d", &x);
            if(toggle[x] == 0)
            {
                sum += arr[x];
                toggle[x] = 1;
                if(max < sum)
                    max = sum;
            }

            else
            {
                toggle[x] = 0;
                sum -= arr[x];
            }
        }

        printf("Sequence %d\n", ++cnt);
        if(max > c)
            printf("Fuse was blown.\n\n");
        else
            printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", max);
    }
    return 0;
}
