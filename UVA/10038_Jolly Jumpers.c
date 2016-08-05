#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, p, x;
    while(scanf("%d", &n) == 1)
    {
        int a[n], b[n];
        for(i = 1; i < n; ++i)
            b[i] = i;
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        p = 1;
        for(i = 0; i < n - 1; ++i)
        {
            x = abs(a[i] - a[i + 1]);
            if(x >= 1 && x < n)
            {
                if(b[x] == 0)
                {
                    p = 0;
                    break;
                }
                else
                    b[x] = 0;
            }
            else
            {
                p = 0;
                break;
            }
        }
        if(p == 1)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
    }
    return 0;
}
