#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

double arr[10000005];

int main()
{
    long long i, n, t;

    for(i = 1; i <= 10000000; ++i)
        arr[i] = arr[i - 1] + log10(i);

    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", (long long)(floor(arr[n]) + 1));
    }
    return 0;
}
