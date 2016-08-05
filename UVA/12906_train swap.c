#include <stdio.h>
int main()
{
    int n, cnt, i, temp, arr[1050], j, t, k;
    scanf("%d", &t);
    for(k = 1; k <= t; ++k)
    {
    scanf("%d", &n);
    for(cnt = 0; cnt < n; ++cnt)
    {
        scanf("%d", &arr[cnt]);
    }
    j = 0;
    for(cnt = 0; cnt < n - 1; ++cnt)
        for(i = cnt + 1; i < n; ++i)
        {
            if(arr[i] < arr[cnt])
            {
                temp = arr[cnt];
                arr[cnt] = arr[i];
                arr[i] = temp;
                ++j;
            }
        }
    printf("Optimal train swapping takes %d swaps.\n", j);
    }
    return 0;
}

