#include <stdio.h>
int main()
{
    long long int i = 0, n, cnt, arr[20], ans1, ans2, x, j, k, ans;
    while(scanf("%lld", &n) == 1)
    {
        for(j = 0; j < n; ++j)
            scanf("%lld", &arr[j]);
        ans1 = 0;
        x = 0;
        for(j = 0; j < n; ++j)
        {
            for(cnt = 0; cnt < n; ++cnt)
            {
                ans2 = 1;
                for(k = cnt; k <= cnt + x; ++k)
                {
                    ans2 *= arr[k];
                }

                if(ans1 < ans2)
                {
                    ans1 = ans2;
                }

                if(cnt + x == n - 1)
                    break;
            }
            ++x;
        }
        ++i;
        printf("Case #%lld: The maximum product is %lld.\n\n", i, ans1);
    }
    return 0;
}
