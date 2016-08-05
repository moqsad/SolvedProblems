#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, cnt, n, i, sum, a;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        sum = 0;
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            if(a > 0)
                sum += a;
        }
        printf("Case %d: %d\n", cnt, sum);
    }
    return 0;
}

