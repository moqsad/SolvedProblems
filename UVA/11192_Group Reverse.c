#include <stdio.h>
#include <string.h>
int main()
{
    int count, i, n, x, y, z, p;
    char arr[150];
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        scanf("%s", arr);
        y = strlen(arr) / n;
        count = 0;
        i = 0;
        p = strlen(arr);
        while(count < p)
        {
            ++i;
            x = y * i;
            z = x;
            while(z - count != 0)
            {
                putchar(arr[--x]);
                ++count;
            }
        }
        printf("\n");
    }
    return 0;
}
