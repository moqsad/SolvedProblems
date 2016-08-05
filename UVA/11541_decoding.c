#include <stdio.h>
int main()
{
    int n, cnt, i, j, num, y;
    char arr[300], x;
    scanf("%d", &n);
    for(cnt = 1; cnt <= n; ++cnt)
    {
        scanf("%s", arr);
        printf("Case %d: ", cnt);
        i = 0;
        while(arr[i] != '\0')
        {
            x = arr[i];
            ++i;
            y = i;
            num = arr[i] - 48;
            while(arr[i] >= '0' && arr[i] <= '9')
            {
                ++i;
                if(arr[i] >= '0' && arr[i] <= '9')
                    num = num * 10 + arr[i] - 48;
            }
            for(j = 1; j <= num; ++j)
                putchar(x);
        }
        printf("\n");
    }
    return 0;
}
