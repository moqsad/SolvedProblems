#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int t, cnt, n, k, x;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d", &n, &k, &x);
        k += x;
        n = n * (n + 1) / 2 - k * (k - 1) / 2 + x * (x - 1) / 2;
        printf("Case %d: %d\n", cnt, n);
    }
    return 0;
}
