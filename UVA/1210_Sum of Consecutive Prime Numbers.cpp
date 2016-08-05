#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int prime[2000];
bool arr[10010];

int main()
{
    int  cnt = 0, n, i, j, k, sum;
    prime[cnt++] = 2;
    for(i = 3; i < 102; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt++] = i;
            k = i + i;
            for(j = i * i; j < 10010; j += k)
                arr[j] = 1;
        }
    }

    for(i = i; i < 10010; i += 2)
        if(arr[i] == 0)
        prime[cnt++] = i;

    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        k = 0;
        for(i = 0; prime[i] <= n; ++i)
        {
            j = i;
            sum = 0;
            while(sum < n)
                sum += prime[j++];
            if(sum == n)
                ++k;
        }
        printf("%d\n", k);
    }

    return 0;
}

