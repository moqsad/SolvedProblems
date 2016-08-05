#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <iostream>
using namespace std;

int prime[5762000], arr[12500010], cnt;

struct data
{
    int index, value;
};

data info[];

void sieve()
{
    int i, cnt = 0, j, k;

    prime[cnt++] = 2;

    for(i = 3; i < 10010; i += 2)
    {
        if((arr[i / 32] & (1 << (i % 32))) == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 100000010; j += k)
                arr[j / 32] = arr[j / 32] | (1 << (j % 32));
        }
    }

    for(; i < 100000010; i += 2)
    {
        if((arr[i / 32] & (1 << (i % 32))) == 0)
            prime[cnt++] = i;
    }

    printf("%d\n", cnt);

    return ;
}

void func()
{
    memset(arr, 0, sizeof(arr));

    int i, j;
    long long x, sz;

    for(i = 0; i < cnt; ++i)
    {
        x = prime[i];

        while(x <= sz)
        {
            arr[x / 32] = arr[x / 32] | (1 << (x % 32));
            x *= x;
        }
    }


}

int main()
{
    int t, n;

    sieve();

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        //printf("Case %d: %d\n", cnt, ans[n]);
    }

    return 0;
}


