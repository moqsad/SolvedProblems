#include <stdio.h>
int main()
{
    int a, b, count, m, n, t;
    while(1)
    {
        scanf("%d", &t);
        if(t == 0)
            break;
        scanf("%d %d", &m, &n);
        for(count = 1; count <= t; ++count)
        {
            while(1)
            {
                scanf("%d %d", &a, &b);
                if(m - a == 0 || n - b == 0)
                {
                    printf("divisa\n");
                    break;
                }
                if(m - a > 0 && n - b > 0)
                {
                    printf("SO\n");
                    break;
                }
                if(m - a < 0 && n - b > 0)
                {
                    printf("SE\n");
                    break;
                }
                if(m - a < 0 && n - b < 0)
                {
                    printf("NE\n");
                    break;
                }
                if(m - a > 0 && n - b < 0)
                {
                    printf("NO\n");
                    break;
                }
            }
        }
    }
    return 0;
}
