#include <stdio.h>
int main()
{
    unsigned int a, b, count, x, y;
    while(1)
    {
        scanf("%u %u", &a, &b);
        if(a == 0 && b == 0)
            break;
        count = 0;
        x = 0;
        while(!(a == 0 || b == 0))
        {
            if(a % 10 + b %10 + x >= 10)
            {
                ++count;
                a /= 10;
                b = b / 10;
                x = 1;
            }
            else
            {
                a /= 10;
                b /= 10;
                x = 0;
            }
        }
        y = (a > b) ? a : b;
        if(x == 1)
        while(y % 10 == 9)
        {
        y /= 10;
        ++count;
        }
        if(count == 0)
        printf("No carry operation.\n");
        else if(count == 1)
        printf("%u carry operation.\n", count);
        else
        printf("%u carry operations.\n", count);
    }
    return 0;
}
