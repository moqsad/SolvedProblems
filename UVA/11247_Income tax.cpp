#include "bits/stdc++.h"
using namespace std;

int main()
{
    long long int m, x, ans, mod;
    while(scanf("%lld %lld", &m, &x) == 2)
    {
        if(m == 0 && x == 0)
            break;
        if(x == 0 || x == 100)
            printf("Not found\n");
        else
        {
            ans = (m - 1) * 100 / (100 - x);
            mod = (m - 1) * 100 % (100 - x);
            if(mod > 0)
            {
                if(ans >= m)
                    printf("%lld\n", ans);
                else
                    printf("Not found\n");
            }
            else
            {
                if(ans > m)
                    printf("%lld\n", --ans);
                else
                    printf("Not found\n");
            }
        }
    }
    return 0;
}
