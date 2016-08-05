#include <stdio.h>
int f91(int n);
int main()
{
    int n, x;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
        break;
        x = f91(n);
        printf("f91(%d) = %d\n", n, x);
    }
    return 0;
}

int f91(int n)
{
    if (n <= 100)
    return(f91(f91(n+11)));
    if(n >= 101)
    return(n - 10);
}
