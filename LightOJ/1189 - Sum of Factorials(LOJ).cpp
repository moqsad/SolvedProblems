#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    long long t, cnt, n, x, p, ans, i, arr[25], num[25], j;
    arr[0] = 1;
    for(i = 1; i < 20; ++i)
        arr[i] = arr[i - 1] * i;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);
        ans = 0;
        x = n;
        j = 0;
        p = 0;
        for(i = 19; i >= 0; --i)
        {
            if(arr[i] <= x)
            {
                num[j++] = i;
                ans += arr[i];
                x = n - ans;
                if(ans == n)
                {
                    p = 1;
                    break;
                }
            }
        }
        if(p == 1)
        {
            printf("Case %lld: %lld!", cnt, num[j - 1]);
            for(i = j - 2; i >= 0; --i)
                printf("+%lld!", num[i]);
            printf("\n");
        }
        else
            printf("Case %lld: impossible\n", cnt);
    }
    return 0;
}
