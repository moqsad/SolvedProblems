#include <stdio.h>
int main()
{
    int num[15], cnt, n, i, j, x, sum;
    char arr[15][30];
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        getchar();
        x = 30;
        for(cnt = 0; cnt < n; ++cnt)
        {
            gets(arr[cnt]);
            j = 0;
            for(i = 1; i < 24; ++i)
            {
                if(arr[cnt][i] == ' ')
                    ++j;
            }
            num[cnt] = j;
            if(j < x)
                x = j;
        }
        sum = 0;
        for(cnt = 0; cnt < n; ++cnt)
            sum += num[cnt] - x;
        printf("%d\n", sum);
    }
    return 0;
}
