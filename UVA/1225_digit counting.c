#include <stdio.h>
int main()
{
    int a, cnt, arr[10], x, b, t, i, n;
    scanf("%d", &t);
    for(i = 0; i < t; ++i)
    {
        for(cnt = 0; cnt < 10; ++cnt)
            arr[cnt] = 0;
           scanf("%d", &n);
           ++n;
        for(cnt = 1; cnt < n; ++cnt)
        {
            x = cnt;
            while(x > 0)
            {
                b = x % 10;
                x /= 10;
                ++arr[b];
            }
        }
        for(cnt = 0; cnt < 9; ++cnt)
            printf("%d ", arr[cnt]);
            printf("%d\n", arr[cnt]);
    }
    return 0;
}
