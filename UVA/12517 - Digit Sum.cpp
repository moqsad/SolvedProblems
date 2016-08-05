#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    long long a, b, i, j, k;
    while(scanf("%lld %lld", &a, &b) == 2)
    {
        if(a == 0 && b == 0)
            break;

        i = 0;
        while(a > 0)
        {
            arr[i++] = a % 10;
            a /= 10;
        }

        k = 0;
        for(j = i - 1; j >= 0; --j)
            num[k++] = arr[j];


    }
    return 0;
}
