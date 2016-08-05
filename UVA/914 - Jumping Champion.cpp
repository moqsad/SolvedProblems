#include <cstdio>
#include <map>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

map <long long, long long> mm;
map <long long, long long> nn;

bool arr[1000010];
long long prime[80000];
long long ans[1000010];

int main()
{
    long long cnt = 0, i, j, k, x, y, n, a, b, total;
    prime[cnt++] = 2;
    for(i = 3; i < 1000010; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 1000010; j += k)
                arr[j] = 1;
        }
    }

    scanf("%lld", &n);
    for(k = 0; k < n; ++k)
    {
        scanf("%lld %lld", &a, &b);
        memset(ans, 0, sizeof(ans));
        cnt = 0;
        i = 0;
//        printf("%lld %lld__________________\n", a, b);
        while(prime[cnt] <= b)
        {
            if(prime[cnt] >= a)
            {
                x = prime[cnt];
//                printf("%lld__\n", x);
                break;
            }
            ++cnt;
        }
        while(prime[++cnt] <= b)
        {
            y = prime[cnt] - x;
            x = prime[cnt];
            if(mm.find(y) == mm.end())
            {
                mm[y] = ++i;
                nn[i] = y;
            }
            ++ans[mm[y]];
        }
        total = 0;
        for(j = 1; j <= i; ++j)
        {
            if(ans[j] > total)
            {
                total = ans[j];
                x = j;
            }
        }
        y = 0;
        for(j = 1; j <= i; ++j)
        {
            if(ans[j] == total)
                ++y;
        }

        if(y > 1 || total == 0)
        {
            printf("No jumping champion\n");
        }
        else
            printf("The jumping champion is %d\n", nn[x]);
        mm.clear();
        nn.clear();
    }
    return 0;
}
