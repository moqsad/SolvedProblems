#include <stdio.h>

int main()
{
    long long n, arr[20], i, j, ans, p, cnt = 0;
    while(scanf("%lld", &n) == 1)
    {
        for(i = 0; i < n; ++i)
            scanf("%lld", &arr[i]);

        ans = 0;
        for(i = 0; i < n; ++i)
        {
            p = 1;
            for(j = i; j < n; ++j)
            {
                p *= arr[j];
                if(p > ans)
                    ans = p;
            }
        }
        printf("Case #%lld: The maximum product is %lld.\n\n", ++cnt, ans);
    }
    return 0;
}
