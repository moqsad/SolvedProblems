#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int arr[100010];

int main()
{
    int cnt, t, x, a, i, n, y;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        x = 0;

        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
            a = arr[i] - arr[i - 1];
            if(a > x)
                x = a;
        }

        y = x;
        for(i = 1; i <= n; ++i)
        {
            a = arr[i] - arr[i-1];
            if(a == x)
                --x;
            else if(a > x)
                break;
        }

        if(i > n)
            printf("Case %d: %d\n", cnt, y);
        else
            printf("Case %d: %d\n", cnt, y + 1);
    }
    return 0;
}
