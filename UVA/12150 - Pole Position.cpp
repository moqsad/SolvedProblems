#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long arr[10010];

int main()
{
    long long n, p, i, a, b;
    while(scanf("%lld", &n) == 1)
    {
        if(n == 0)
        break;

        memset(arr, -1, sizeof(arr));
        p = 1;
        for(i = 1; i <= n; ++i)
        {
            scanf("%lld %lld", &a, &b);
            if(p == 1)
            {
                if(i + b > 0 && i + b <= n && arr[i + b] == -1)
                    arr[i + b] = a;
                else
                    p = 0;
            }
        }

        if(p == 0)
            printf("-1\n");
        else
        {
            printf("%lld", arr[1]);
            for(i = 2; i <= n; ++i)
                printf(" %lld", arr[i]);
            printf("\n");
        }
    }
    return 0;
}
