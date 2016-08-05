#include <stdio.h>
int main()
{
    int i, n, count, arr[10][10], x, y, sum, k = 1;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        for(count = 0; count < n; ++count)
            for(i = 0; i < n; ++i)
                scanf("%d", &arr[count][i]);
        x = 0;
        y = n - 1;
        printf("Case %d: ", k);
        while(y >= x)
        {
            sum = 0;
            for(count = x; count <= y; ++count)
            {
                for(i = x; i <= y; ++i)
                {
                    if(count == x || count == y || i == x || i == y)
                        sum += arr[count][i];
                }
            }
            printf("%d", sum);
            x += 1;
            y -= 1;
            if(x > y)
                break;
            printf(" ");
        }
        printf("\n");
        ++k;
    }
    return 0;
}
