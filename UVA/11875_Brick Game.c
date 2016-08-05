#include <stdio.h>
int main()
{
    int arr[9], n, t, i, count;
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
        printf("Case %d: %d\n", count, arr[n / 2]);
    }
    return 0;
}
