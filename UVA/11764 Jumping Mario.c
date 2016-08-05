#include <stdio.h>
int main()
{
    int t, n, count, i, arr[50], higher, lower;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        higher = 0, lower = 0;
        scanf("%d", &t);
        for(i = 0; i < t; ++i)
        scanf("%d", &arr[i]);
        for(i = 1; i < t; ++i)
        {
            if(arr[i] > arr[i - 1])
            higher += 1;
            else if(arr[i] < arr[i - 1])
            lower += 1;
        }
        printf("Case %d: %d %d\n", count, higher, lower);
    }
    return 0;
}
