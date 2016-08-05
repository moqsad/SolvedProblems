#include <stdio.h>
#include <string.h>
int main()
{
    int t, count, ans = 0, n;
    char arr[10];
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%s", arr);
        if(strcmp(arr, "donate") == 0)
        {
            scanf("%d", &n);
            ans += n;
        }
        else
            printf("%d\n", ans);
    }
    return 0;
}
