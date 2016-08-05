#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define max_ 1000005

bool arr[max_];

char n[15], temp[15];

void sieve()
{
    long long i, j, k;

    for(i = 4; i < max_; i += 2)
        arr[i] = 1;

    for(i = 3; i < max_; i += 2)
    {
        if(!arr[i])
        {
            k = i + i;

            for(j = i * i; j < max_; j += k)
                arr[j] = 1;
        }
    }
}

int main()
{
    sieve();

    long long i, j;
    while(scanf("%s", n) == 1)
    {
        printf("%d\n", 2 * atoi(n));

        if(!arr[atoi(n)])
        {
            i = 0;
            for(j = strlen(n) - 1; j >= 0; --j)
                temp[i++] = n[j];
            temp[i] = '\0';

            if(!strcmp(n, temp))
                break;
        }
    }
    return 0;
}
