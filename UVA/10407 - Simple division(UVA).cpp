#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

/*
jekono duita number er difference holo sei maximum number jake dia oi duita number ke mod korle number
duitar remainder same hobe, ekisathe number duitar difference er divisor gula dia number duitake mod
korleo same remainder paoa jai........., kintu number duitar difference er chae boro ba choto(kintu
difference er divisor noi) amon kono number dia number duitake mod korle remainder same paoa jai na.
*/

long long abs2(long long a, long long b)
{
    if(a > b)
        return a - b;
    return b - a;
}

int main()
{
    long long a, pre, i, gcd;

    while(scanf("%lld", &a) == 1 && a)
    {
        i = 0;
        pre = a;
        while(scanf("%lld", &a) == 1 && a)
        {
            if(i)
                gcd = __gcd(gcd, abs2(a, pre));
            else
            {
                i = 1;
                gcd = abs2(a, pre);
            }
            pre = a;
        }
        printf("%lld\n", gcd);
    }

    return 0;
}
