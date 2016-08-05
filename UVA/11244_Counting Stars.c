#include <stdio.h>
int main()
{
    int m, n, count, i, x, ans, p;
    char arr[150][150];
    while(1)
    {
        scanf("%d %d", &m, &n);
        if(m == 0 && n == 0)
            break;
        ans = 0;
        for(count = 0; count < m; ++count)
            scanf("%s", arr[count]);
        for(count = 0; count < m; ++count)
            for(i = 0; i < n; ++i)
            {
                if(arr[count][i] == '*')
                {
                p = 1;
                if(count - 1 >= 0 && count - 1 < m)
                    for(x = i - 1; x <= i + 1; ++x)
                        if(x >= 0 && x < n)
                        {
                            if(arr[count - 1][x] == '*')
                            {
                                p = 0;
                                break;
                            }
                        }
                if(p == 1 && count + 1 >= 0 && count + 1 < m)
                        for(x = i - 1; x <= i + 1; ++x)
                            if(x >= 0 && x < n)
                            {
                                if(arr[count + 1][x] == '*')
                                {
                                    p = 0;
                                    break;
                                }
                            }
                if(p == 1 && (arr[count][i - 1] == '*' || arr[count][i + 1] == '*'))
                    p = 0;
                if(p == 1)
                    ++ans;
                }
            }
            printf("%d\n", ans);
    }
    return 0;
}
