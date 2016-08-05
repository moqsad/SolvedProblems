#include <stdio.h>
int main()
{
    int arr[3651], count, num[110], i, j, k, x, y, ans, t, n;
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%d", &k);
        x = 6;
        for(j = 1; j <= k; ++j)
        {
            if(j != x && j != x + 1)
            arr[j] = 1;
            else if(j == x)
            arr[j] = 0;
            else
            {
                arr[j] = 0;
                x += 7;
            }
        }
        ans = 0;
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &num[i]);
            for(y = num[i]; y <= k; y += num[i])
            {
                if(arr[y] == 1)
                {
                    ++ans;
                    arr[y] = 0;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
