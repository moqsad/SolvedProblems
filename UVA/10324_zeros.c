#include <stdio.h>
int main()
{
    int count = 0, i, n, a, b, j, p, x, y;
    char arr[1000000];
    while(gets(arr))
    {
        if(arr[0] == '\0')
        break;
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%d %d", &a, &b);
            if(i == 0)
            printf("Case %d:\n", ++count);
            x = (a <= b) ? a : b;
                y = (a >= b) ? a : b;
            if(x == y)
                printf("Yes\n");
            else
            {
                p = 1;
                for(j = x; j <= y - 1; ++j)
                    if(arr[j] != arr[j + 1])
                    {
                        printf("No\n");
                        p = 0;
                        break;
                    }
                if(p == 1)
                    printf("Yes\n");
            }
        }
    getchar();
    }
    return 0;
}
