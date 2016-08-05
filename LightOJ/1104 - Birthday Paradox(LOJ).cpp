#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, cnt, i, n;
    double ans = 1;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        i = 1;
        ans = 1;

        while(ans > .5)
        {
            ans *= (double)(n - i) / (double)n;
            ++i;
        }

        printf("Case %d: %d\n", cnt, --i);
    }
    return 0;
}
