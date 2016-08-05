#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t, x, y, count;
    char arr[10];
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%s", &arr);
        x = (arr[0] - 65) * 26 * 26 + (arr[1] - 65) * 26 + (arr[2] - 65);
        y = (arr[4] - 48) * 1000 + (arr[5] - 48) * 100 + (arr[6] - 48) * 10 + (arr[7] - 48);
        if(abs(y - x) >= 0 && abs(y - x) <= 100)
            printf("nice\n");
        else
            printf("not nice\n");
    }
    return 0;
}
