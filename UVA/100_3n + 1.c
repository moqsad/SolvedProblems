#include <stdio.h>

long long int arr[1000000];

int main()
{
    long long int cnt, i, a, x, y, z, b;
    for(cnt = 1; cnt < 1000000; ++cnt)
    {
        i = 0;
        a = cnt;
        while(a > 1)
        {
            if(a % 2 == 1)
                a = 3 * a + 1;
            else
                a /= 2;
            ++i;
        }
        arr[cnt] = i;
    }
    while(scanf("%lld %lld", &x, &y) == 2)
    {
        a = (x < y) ? x : y;
        b = (x > y) ? x : y;
        z = arr[a];
        for(i = a + 1; i <= b; ++i)
            if(z < arr[i])
                z = arr[i];
        printf("%lld %lld %lld\n", x, y, ++z);
    }
    return 0;
}
