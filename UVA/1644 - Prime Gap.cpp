#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

long long arr[1500000], prime[100015];

map <long long, long long> mm;

int main()
{
    long long cnt = 2, i, j, k, n;
//    prime[1] = 1;
//    prime[2] = 2;
    for(i = 2; i < 1299725; ++i)
    {
        if(arr[i] == 0)
        {
            k = i;
            prime[++cnt] = i;
            for(j = i * i; j <= 1299725; j += k)
                arr[j] = 1;
        }
        mm[i] = cnt;
    }

    while(scanf("%lld", &n) == 1)
    {
        if(n == 0)
            break;
//        printf("%lld______\n", mm[n]);
        if(arr[n] == 0)
            printf("0\n");
        else
            printf("%lld\n", prime[mm[n] + 1] - prime[mm[n]]);
    }
    return 0;
}
