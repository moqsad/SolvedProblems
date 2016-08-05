#include "bits/stdc++.h"
using namespace std;

long long int arr[1000050],  num[80071];
map <long long int, long long int> mm;

int main()
{
    long long int i, j, cnt = 0, x, k, t, prime[90000], a, b, sum, m, n, l = 0;
    prime[cnt] = 2;
    num[l] = 4;
    while(num[l] < 1000000000000)
    {
        x = num[l];
        num[++l] = x * prime[cnt];
    }
    ++cnt;
    for(i = 3; i < 1000050; i += 2)
    {
        if(arr[i] == 0)
        {
            prime[cnt] = i;
            num[l] = i * i;
            while(num[l] < 1000000000000)
            {
                x = num[l];
                num[++l] = x * prime[cnt];
            }
            k = i + i;
            for(j = i * i; j < 1000050; j += k)
            {
                arr[j] = 1;
            }
            ++cnt;
        }
    }
    sort(num, num + 80070);

    scanf("%lld", &t);
    for(i = 0; i < t; ++i)
    {
        scanf("%lld %lld", &a, &b);
        cnt = 0;
        j = 0;
        while(num[cnt] <= b)
            {
            if(num[cnt] >= a && num[cnt] <= b)
                ++j;
                ++cnt;
            }
            printf("%lld\n", j);
    }
    return 0;
}

