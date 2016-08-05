#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

long long rec(long long n)
{
    if(n == 0)
        return 0;

    return rec(n / 2) + n % 2;
}

int main()
{
    long long t, cnt, n;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);
        printf("%lld\n", rec(n));
    }
    return 0;
}
