#include <stdio.h>
int main()
{
    int i, count, t, n, num[150], x, ans;
    char arr[15];
    scanf("%d\n", &t);
    for(count = 1; count <= t; ++count)
    {
        ans = 0;
        scanf("%d\n", &n);
        for(i = 1; i <= n; ++i)
        {
            gets(arr);
            if(arr[0] == 'L')
            {
                num[i] = -1;
                ans += num[i];
            }
            else if(arr[0] == 'R')
            {
                num[i] = 1;
                ans += num[i];
            }
            else
            {
                x = arr[8] - 48;
                if(arr[9] != '\0')
                {
                    x = x * 10 + arr[9] - 48;
                }
                num[i] = num[x];
                ans += num[i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
