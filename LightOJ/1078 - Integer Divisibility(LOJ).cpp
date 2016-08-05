#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int t, cnt, x, i, k, n;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &k);
        i = 1;
        x = k;
        while(x % n != 0)
        {
            x = (x * 10 + k) % n;
            ++i;
        }
        printf("Case %d: %d\n", cnt, i);
    }
    return 0;
}
