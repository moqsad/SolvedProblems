#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, q, l[50010], h[50010];

int binary_func1(int x)
{
    int s = 1, e = n, mid;
    mid = (s + e) / 2;

    while(s <= e)
    {
//        printf("%d ___  %d\n", s, e);
        if(x < l[mid])
            e = mid - 1;
        else
            s = mid + 1;
        mid = (s + e) / 2;
    }
//    printf("%d_______________________________\n", s);
    return s;
}

int binary_func2(int x)
{
    int s = 1, e = n, mid;
    mid = (s + e) / 2;

    while(s <= e)
    {
//        printf("%d ++++  %d\n", s, e);
        if(x > h[mid])
            s = mid + 1;
        else
            e = mid - 1;
        mid = (s + e) / 2;
    }
//    printf("%d++++++++++++++++++++++++++++++\n", e);

    return e;
}

int main()
{
    int t, cnt, i, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &q);

        for(i = 1; i <= n; ++i)
            scanf("%d %d", &l[i], &h[i]);

        sort(l + 1, l + n + 1);
        sort(h + 1, h + n + 1);

        printf("Case %d:\n", cnt);
        for(i = 0; i < q; ++i)
        {
            scanf("%d", &x);
            printf("%d\n", binary_func1(x) - binary_func2(x) - 1);
        }
    }
    return 0;
}
