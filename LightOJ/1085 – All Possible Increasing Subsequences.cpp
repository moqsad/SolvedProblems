#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

long long arr[1000010];

int main()
{
    long long t, cnt, n, i, ans, ans2, x;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);

        for(i = 0; i < n; ++i)
            scanf("%lld", &arr[i]);

        ans2 = ans = 1;
        x = 0;

        for(i = 1; i < n; ++i)
        {
//            printf("%d %d_____\n", ans, x);
            if(arr[i] == arr[i - 1])
                ans += x + 1;

            else if(arr[i] > arr[i - 1])
            {
                x = ans;
                ans = ans + ans + 1;
            }

            else
            {
                ans2 = (ans2 + ans) % 1000000007;
                ans = 1;
                x = 0;
            }

            ans = ans % 1000000007;
        }

        printf("Case %lld: %lld\n", cnt, ans2);
    }
    return 0;
}
