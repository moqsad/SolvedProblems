#include <cstring>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

int arr[100100];

int main()
{
    int n, g, ans, i, j, s, r;
    while(scanf("%d %d", &n, &g) == 2)
    {
        ans = 0;
        j = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%d %d", &s, &r);
            if(s > r)
                ans += 3;
            else
            {
                arr[j++] = r - s;
            }
        }

        sort(arr, arr + j);
        for(i = 0; i < j; ++i)
        {
            if(g > arr[i])
            {
                ans += 3;
                g = g - arr[i] - 1;
            }

            else if(g == arr[i])
            {
                ans += 1;
                g = g - arr[i];
            }

            else
                break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
