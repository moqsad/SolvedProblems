#include <stdio.h>
int main()
{
    int n, cnt, i, temp, arr[1050], j, y, x, ans, p, k;
    while(scanf("%d", &n) == 1)
    {
        for(cnt = 0; cnt < n; ++cnt)
        {
            scanf("%d", &arr[cnt]);
        }
        ans = 0;
        for(cnt = 0; cnt < n - 1; ++cnt)
        {
            x = cnt;
            y = cnt;
            p = arr[cnt];
            for(i = cnt + 1; i < n; ++i)
            {
                if(arr[y] > arr[i] && arr[i] != p)
                    {
                        y = i;
                        p = arr[i];
                    }
            }
            if(y > x)
            {
                for(j = y; j > x; --j)
                {
                    temp = arr[j];
                    arr[j] = arr[j - 1];
                    arr[j - 1] = temp;
                    ++ans;
                }
            }
        }
        printf("Minimum exchange operations : %d\n", ans);
    }
    return 0;
}
