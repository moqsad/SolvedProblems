#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int binary_func(int data, int s, int e)
{
    int mid = (s + e) / 2, x, ans = 0;

    while(s <= e)
    {
        x = mid;

        while(x > 0)
        {
            ans += x / 5;
            x /= 5;
        }

        if(data > ans)
            s = mid + 1;
        else
            e = mid - 1;

        mid = (s + e) / 2;
        ans = 0;
    }

    return e;
}

int main()
{
    int t, cnt, x, ans, y, q;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &q);
        y = x = binary_func(q, 1, 5 * q) + 1;
        ans = 0;
        while(x > 0)
        {
            ans += x / 5;
            x /= 5;
        }
        if(ans == q)
            printf("Case %d: %d\n", cnt, y);
        else
            printf("Case %d: impossible\n", cnt);
    }
    return 0;
}
