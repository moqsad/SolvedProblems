#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
return ( *(int*)b - *(int*)a );
}

int main()
{
    int n, cnt, t, i, j, arr[500], sum = 0;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 0; i < 500; ++i)
        arr[i] = 0;
        sum = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &arr[i]);
        }
        qsort(arr, 500, sizeof(int), cmpfunc);
        for(i = 0; i < n; ++i)
        {
            sum += abs(arr[i] - arr[n / 2]);
        }
        printf("%d\n", sum);
    }
    return 0;
}
