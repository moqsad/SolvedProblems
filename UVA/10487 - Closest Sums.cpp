#include <cstdio>
#include <iostream>
using namespace std;

int arr[1100];

int main()
{
    int n, m, i, j, k, a, x, y, z, ans, cnt = 0, p;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        printf("Case %d:\n", ++cnt);
        scanf("%d", &m);
        for(k = 0; k < m; ++k)
        {
            p = 0;
            y = 1000000000;
            scanf("%d", &a);
            for(i = 0; i < n; ++i)
            {
                for(j = i + 1; j < n; ++j)
                {
                    x = arr[i] + arr[j];
                    if(x > a)
                        z = x - a;
                    else
                        z = a - x;
                    if(z < y)
                    {
                        y = z;
                        ans = x;
                        if(ans == a)
                        {
                            p = 1;
                            break;
                        }
                    }
                }
                if(p == 1)
                    break;
            }
            printf("Closest sum to %d is %d.\n", a, ans);
        }
    }
    return 0;
}
