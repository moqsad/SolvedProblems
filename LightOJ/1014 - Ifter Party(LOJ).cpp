#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int arr[50000];

int main()
{
    int t, cnt, x, y, n, m, i, j;
    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        j = 0;
        scanf("%d %d", &n, &m);
        n -= m;
        x = sqrt(n) + 1;
        printf("Case %d:", cnt);

        for(i = 1; i < x; ++i)
        {
            if(n % i == 0)
            {
                y = n / i;
                if(y > m)
                arr[j++] = y;
                if(i > m)
                    printf(" %d", i);
            }
        }

        if(j > 0 && arr[j-1] != i - 1 && arr[j-1] > m)
            printf(" %d", arr[j-1]);

        for(i = j - 2; i >= 0; --i)
            printf(" %d", arr[i]);

        if(j == 0)
            printf(" impossible");
        printf("\n");
    }

    return 0;
}
