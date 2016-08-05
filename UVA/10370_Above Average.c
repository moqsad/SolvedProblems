#include <stdio.h>
int main()
{
    int t, n, arr[1000], i, count;
    float add, average, ans, inc;
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%d", &n);
        add = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
            add += arr[i];
        }
        average = add / n;
        inc = 0;
        for(i = 0; i < n; ++i)
        {
            if(arr[i] > average)
            ++inc;
        }
        ans = inc / n * 100;
        printf("%.3f%%\n", ans);
    }
    return 0;
}
