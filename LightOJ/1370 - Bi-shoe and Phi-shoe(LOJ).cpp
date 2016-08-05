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

int prime[78500], ans[1000010];

bool arr[1000010];

void sieve()
{
    int i, j, k, cnt = 0;

    prime[cnt++] = 2;

    for(i = 3; i <= 1010; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 1000010; j += k)
                arr[j] = 1;
        }
    }

    for(; i < 1000010; i += 2)
    {
        if(arr[i] == 0)
            prime[cnt++] = i;
    }
}

void func()
{
    int start = 1, i = 0;

    while(start < 1000001)
    {
        if(start >= prime[i])
            ++i;
        ans[start] = prime[i];
        ++start;
    }
}

int main()
{
    int t, cnt, n, i, a;
    long long sum = 0;

    sieve();
    func();

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        sum = 0;

        for(i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            sum += ans[a];
        }

        printf("Case %d: %lld Xukha\n", cnt, sum);
    }

    return 0;
}

