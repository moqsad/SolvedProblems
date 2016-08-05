#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int prime[200], arr[1010];

int main()
{
    int n, i, j, k, cnt = 0, x, y;
    prime[cnt++] = 2;
    for(i = 3; i < 1010; i += 2)
    {
        if(arr[i] == 0)
        {
            k = i + i;
            prime[cnt++] = i;
            for(j = i * i; j < 1010; j += k)
                arr[j] = 1;
        }
    }
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        i = 0;
        j = 0;
        y = n;
        x = sqrt(n) + 1;
        while(prime[i] < x)
        {
            if(y % prime[i] == 0)
            {
                while(y % prime[i] == 0)
                    y /= prime[i];
                    ++j;
                x = sqrt(y) + 1;
//            printf("%d %d %d\n", prime[i], x, y);
            }
            ++i;
        }
        if(y > 1)
            ++j;
        printf("%d : %d\n", n, j);
    }
    return 0;
}
