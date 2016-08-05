#include <stdio.h>
int main()
{
    int a, b, t, x, y, count;
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%d:%d", &a, &b);
        if(b == 0)
            y = 0;
        else
            y = 60 - b;
            if(y == 0)
                x = 12 - a;
            else
                x = 12 - a - 1;
            if(x == 0)
                x = 12;
            if(x < 0)
                x = 11;
        printf("%02d:%02d\n", x, y);
    }
    return 0;
}
