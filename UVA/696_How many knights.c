#include <stdio.h>
int main()
{
    int m, n, x, y;
    while(1)
    {
        scanf("%d %d", &m, &n);
        if(m == 0 && n == 0)
            break;
        x = m * n;
        if(m == 1 || n == 1)
            printf("%d knights may be placed on a %d row %d column board.\n", x, m, n);
        else if(x <= 8)
            printf("4 knights may be placed on a %d row %d column board.\n", m, n);
        else if(m == 2 || n == 2)
            {
                y = x % 8;
                if(y == 6)
                    y = 4;
             printf("%d knights may be placed on a %d row %d column board.\n", (x / 8) * 4 + y, m, n);
            }
        else if(x % 2 == 0)
            printf("%d knights may be placed on a %d row %d column board.\n", x / 2, m, n);
        else
            printf("%d knights may be placed on a %d row %d column board.\n", x / 2 + 1, m, n);
    }
    return 0;
}
