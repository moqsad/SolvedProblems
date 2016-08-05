#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
    return ( *(int *)a - *(int *)b );
}

int main()
{
    int arr[2000000], count, n;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
        break;
        for(count = 0; count < n; ++count)
        scanf("%d", &arr[count]);
        qsort(arr, n, sizeof(int), cmpfunc);
        for(count = 0; count < n - 1; ++count)
        printf("%d ", arr[count]);
        printf("%d\n", arr[n - 1]);
    }
    return 0;
}
