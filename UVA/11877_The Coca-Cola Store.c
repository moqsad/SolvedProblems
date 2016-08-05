#include <stdio.h>
int main()
{
    int a, b;
    while(1)
    {
        b = 0;
        scanf("%d", &a);
        if(a == 0)
        break;
        while(!(a >= 0 && a < 3))
        {
            b += a / 3;
            a = a % 3 + a / 3;
        }
        if(a == 2)
        ++b;
        printf("%d\n", b);
    }
    return 0;
}
