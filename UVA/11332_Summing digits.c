#include <stdio.h>
int main()
{
    int a;
    while(1)
    {
        scanf("%d", &a);
        if(a == 0)
        break;
        if(a % 9 != 0)
        printf("%d\n", a % 9);
        else
        printf("9\n");
    }
    return 0;
}
