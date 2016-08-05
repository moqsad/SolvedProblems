#include <stdio.h>
int main()
{
    int t, m, n, cnt, x, y;
    char ch[2];
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s %d %d", ch, &m, &n);
        if(ch[0] == 'k')
        {
            x = m * n;
            if(m == 1 || n == 1)
                printf("%d\n", x);
            else if(x <= 8)
                printf("4\n");
            else if(m == 2 || n == 2)
            {
                y = x % 8;
                if(y == 6)
                    y = 4;
                printf("%d\n", (x / 8) * 4 + y);
            }
            else if(x % 2 == 0)
                printf("%d\n", x / 2);
            else
                printf("%d\n", x / 2 + 1);
        }
        else if(ch[0] == 'K')
        {
            x = m / 2;
            y = n / 2;
            if(m % 2 == 1)
                x = x + 1;
            if(n % 2 == 1)
                y = y + 1;
            printf("%d\n", x * y);
        }
        else if(ch[0] == 'r')
        {
            x = (m < n) ? m : n;
            printf("%d\n", x);
        }
        else
        {
            if(m == 1 || n == 1 || m * n == 4)
                printf("1\n");
            else if(m * n <= 9)
                printf("2\n");
            else
            {
                x = (m < n) ? m : n;
                printf("%d\n", x);
            }
        }
    }
    return 0;
}
