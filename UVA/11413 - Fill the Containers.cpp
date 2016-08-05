#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int arr[1010];

int main()
{
    int n, m, t, cnt, max_, total, i, j, k, s, e, mid, p;

    while(scanf("%d %d", &n, &m) == 2)
    {
        max_ = 0;
        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
            if(arr[i] > max_)
                max_ = arr[i];
        }

        if(m >= n)
            printf("%d\n", max_);
        else
        {
            e = max_ * n;
            s = 1;

            for(i = 0; i < 200; ++i)
            {
                mid = (s + e) / 2;
                p = 1;
                total = 0;
                k = 1;
                for(j = 1; j <= n; ++j)
                {
                    if(total + arr[j] <= mid)
                        total += arr[j];

                    else if(k < m && arr[j] <= mid)
                    {
                        total = arr[j];
                        ++k;
                    }

                    else
                    {
                        p = 0;
                        break;
                    }
                }

                if(p == 1)
                    e = mid;
                else
                    s = mid + 1;
                if(mid == s && mid == e)
                    break;
            }

            printf("%d\n", mid);
        }
    }
    return 0;
}
