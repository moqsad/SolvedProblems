#include <cstdio>
#include <cstring>
long long arr[10010];

long long a, b, c, d, e, f;
long long fn( long long n )
{
    if(arr[n] != -1)
        return arr[n];
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;
    return arr[n] = (fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6)) % 10000007;
}
int main()
{
    long long n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- )
    {
        memset(arr, -1, sizeof(arr));
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
