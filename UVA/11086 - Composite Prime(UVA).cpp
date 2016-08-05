#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

int prime[180], arr[1050000], ans[1050000];

void sieve()
{
    int i, j, k, cnt = 0;

    prime[cnt++] = 2;

    arr[0] = arr[1] = 1;
    for(i = 4; i < 1050000; i += 2)
        arr[i] = 1;

    for(i = 3; i < 1030; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = 2 * i;
            for(j = i * i; j < 1050000; j += k)
                arr[j] = 1;
        }
    }

    for(i = 0; i < cnt; ++i)
        for(j = 1; j < 1048600; ++j)
        {
            if(j % prime[i] == 0)
            {
                k = j / prime[i];
                if(arr[k] == 0)
                    ans[j] = 1;
            }
        }
}

int main()
{
    sieve();
    int k, i, total, a;

    while(scanf("%d", &k) == 1)
    {
        total = 0;
        for(i = 1; i <= k; ++i)
        {
            scanf("%d", &a);
            if(ans[a])
                ++total;
        }
        printf("%d\n", total);
    }
    return 0;
}
