#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[1005];

int main()
{
    int t, cnt, total, n, k, s, e, mid, i, j, p, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &k);

        e = 0;
        n += 2;
        for(i = 1; i < n; ++i)
        {
            scanf("%d", &arr[i]);
            e += arr[i];
        }

        k += 1;
        s = 1;
        mid = (s + e) / 2;
        while(1)
        {
            p = 1;
            j = 1;
            total = 0;
            for(i = 1; i < n; ++i)
            {
                if(total + arr[i] <= mid)
                    total += arr[i];

                else if(arr[i] <= mid && j < k)
                {
                    total = arr[i];
                    ++j;
                }

                else
                {
                    p = 0;
                    break;
                }
            }

            if(p == 0)
                s = mid + 1;
            else
                e = mid;

            mid = (s + e) / 2;
            if(s == e)
                break;
        }

        --n;
        j = 1;
        printf("Case %d: %d\n", cnt, mid);
        for(i = 1; i <= k; ++i)
        {
            x = n - k + i;
            total = 0;
            for(; j <= x; ++j)
            {
                if(total + arr[j] <= mid)
                    total += arr[j];
                else
                    break;
            }
            printf("%d\n", total);
        }
    }
    return 0;
}
