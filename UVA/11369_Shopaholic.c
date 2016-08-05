#include <stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)b - *(int*)a );
}
int main()
{
    int count, i, t, n;
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%d", &n);
        int arr[n], ans;
        for(i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), cmpfunc);
        ans = 0;
        for(i = 2; i < n; i += 3)
        ans += arr[i];
        printf("%d\n", ans);
    }
    return 0;
}
