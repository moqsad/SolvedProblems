#include "bits/stdc++.h"
using namespace std;

int arr[100000];

int main()
{
    int t, n, q, i, j, cnt, a, x, y;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d %d", &n, &q);
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        for(i = 0; i < q; ++i)
        {
            scanf("%d", &a);
            x = a & arr[0];
            for(j = 1; j < n; ++j)
            {
                if(x == a)
                    break;
                y = a & arr[j];
                if(y > x)
                    x = y;
            }
            printf("%d\n", x);
        }
    }
    return 0;
}
