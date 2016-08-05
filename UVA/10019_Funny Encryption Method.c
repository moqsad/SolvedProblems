#include <stdio.h>
#include <string.h>
int main()
{
    int count, i, x, y, z, j, ans, n;
    char arr1[35], arr2[35];
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%s", arr1);
        x = arr1[0] - 48;
        y = strlen(arr1);
        for(i = 1; i < y; ++i)
        {
            x = x * 10 + arr1[i] - 48;
        }
        i = 0;
        while(x != 0)
        {
            arr2[i] = x % 2;
            x /= 2;
            ++i;
        }
        ans = 0;
        for(j = 0; j < i; ++j)
        {
            if(arr2[j] == 1)
                ++ans;
        }
        printf("%d ", ans);
        x = arr1[0] - 48;
        for(i = 1; i < y; ++i)
        {
            x = x * 16 + arr1[i] - 48;
        }
        i = 0;
        while(x != 0)
        {
            arr2[i] = x % 2;
            x /= 2;
            ++i;
        }
        ans = 0;
        for(j = 0; j < i; ++j)
        {
            if(arr2[j] == 1)
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
