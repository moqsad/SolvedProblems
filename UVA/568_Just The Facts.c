#include <stdio.h>

int main()
{
    long long int x, y, cnt, arr[10050], n;
    arr[0] = 1;
    x = 1;
    for(cnt = 1; cnt < 10001; ++cnt)
    {
        y = cnt * x;
        arr[cnt] = y % 10;
        while(arr[cnt] < 1)
        {
            y /= 10;
            arr[cnt] = y % 10;
        }
        x = y % 100000;
    }
    while(scanf("%lld", &n) == 1)
    {
        printf("%5lld -> %lld\n", n, arr[n]);
    }
    return 0;
}
