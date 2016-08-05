#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int n, q, arr[100010];

int binary_searc(int data)
{
    int s = 1, e = n, mid;
    mid = (s + e) / 2;
    while(s <= e)
    {
        if(arr[mid] < data)
            s = mid + 1;
        else
            e = mid - 1;

        mid = (s + e) / 2;
    }
    return e;
}

int binary_searc2(int data)
{
    int s = 1, e = n, mid;
    mid = (s + e) / 2;
    while(s <= e)
    {
        if(arr[mid] > data)
            e = mid - 1;
        else
            s = mid + 1;

        mid = (s + e) / 2;
    }
    return s;
}

int main()
{
    int t, cnt, i, a, b, x, y;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &q);

        for(i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);

        printf("Case %d:\n", cnt);
        for(i = 0; i < q; ++i)
        {
            scanf("%d %d", &a, &b);
            x = binary_searc(a);
            y = binary_searc2(b);
            printf("%d\n", y - x - 1);
        }
    }
    return 0;
}
