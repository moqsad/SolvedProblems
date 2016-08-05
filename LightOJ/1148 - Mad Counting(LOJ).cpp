#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int t, n, cnt, i, j, pre, upto, ans, arr[55];
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 0; i <n; ++i)
            scanf("%d", &arr[i]);

        sort(arr, arr + n);
        pre = -1;
        ans = 0;
        for(i = 0; i < n; ++i)
        {
            if(arr[i] == pre && j < pre)
                ++j;

            else
            {
                pre = arr[i];
                ans += arr[i] + 1;
                j = 0;
            }
        }
        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}
