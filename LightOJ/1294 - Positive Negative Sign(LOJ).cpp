#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    long long t, cnt, n, m;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld %lld", &n, &m);
        printf("Case %lld: %lld\n", cnt, m * n / 2);
    }
    return 0;
}
