#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

long long arr[2010];

long long binary_func(long long data, long long s, long long e)
{
    long long mid = (s + e) / 2;

    while(s <= e)
    {
        if(data < arr[mid])
            e = mid - 1;
        else
            s = mid + 1;

        mid = (s + e) / 2;
    }
    return s;
}

int main()
{
    long long t, cnt, x, n, find_, i, j, ans;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);

        for(i = 1; i <= n; ++i)
            scanf("%lld", &arr[i]);

        sort(arr + 1, arr + n + 1);

        ans = 0;
        x = n - 1;
        for(i = 1; i < x; ++i)
            for(j = i + 1; j <= x; ++j)
            {
                find_ = arr[i] + arr[j];
                ans += binary_func(find_ - 1, j + 1, n) - j - 1;
            }

            printf("Case %lld: %lld\n", cnt, ans);
    }
    return 0;
}
