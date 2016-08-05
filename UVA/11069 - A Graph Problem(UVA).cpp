#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

long long arr[75];

int main()
{
    long long n, i;
    while(scanf("%lld", &n) == 1)
    {
        for(i = n; i > 0; --i)
        {
            if(i + 3 <= n)
                arr[i] = arr[i + 2] + arr[i + 3];
            else if(i + 2 == n)
                arr[i] = arr[i + 2];
            else
                arr[i] = 1;
        }

        if(n > 1)
            printf("%lld\n", arr[1] + arr[2]);
        else
            printf("1\n");
    }
    return 0;
}
