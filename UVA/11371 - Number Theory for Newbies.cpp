#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

char arr[20], digit[20];

int main()
{
    long long int n, m, x, i, j, k, p;
    while(scanf("%lld", &n) == 1)
    {
        x = n;
        i = 0;
        while(x > 0)
        {
            arr[i++] = x % 10 + 48;
            x /= 10;
        }
        arr[i] = '\0';
        sort(arr, arr + i);
        p = 0;
        if(arr[0] == '0')
        {
            for(j = 0; j < i; ++j)
                if(arr[j] != '0')
                {
                    p = 1;
                    arr[0] = arr[j];
                    arr[j] = '0';
                    break;
                }
        }
        n = atol(arr);
        if(p == 1)
        {
            arr[j] = arr[0];
            arr[0] = '0';
        }
        j = 0;
        for(i = i - 1; i >= 0; --i)
            digit[j++] = arr[i];
        digit[j] = '\0';
        m = atol(digit);
        printf("%lld - %lld = %lld = 9 * %lld\n", m, n, m - n, (m - n) / 9);
    }
    return 0;
}
