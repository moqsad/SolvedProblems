#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long int gcd(long long int a, long long int b)
{
    long long int x, y, r;
    x = a;
    y = b;
    while(y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    long long int t, cnt, i, n, a, sum, total, x, arr[20];
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);
        total = 1;
        sum = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%lld", &arr[i]);
            total *= arr[i];
        }
        for(i = 0; i < n; ++i)
        {
            sum += total / arr[i];
        }
        total *= n;
        x = gcd(total, sum);
        printf("Case %lld: %lld/%lld\n", cnt, total / x, sum / x);
    }
    return 0;
}
