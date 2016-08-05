#include <stdio.h>
#include <string.h>
int main()
{
    float x, y;
    int t, count, i;
    char arr[20];
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%s", arr);
        x = arr[0] - 48;
        if(arr[1] >= '0' && arr[1] <= '9')
            x = x * 10 + arr[1] - 48;
        y = 0;
        for(i = 2; i < strlen(arr) - 1; ++i)
            if(arr[i] >= '0' && arr[i] <= '9')
            {
                y = arr[i] - 48;
                break;
            }
        printf("Case %d: %g\n", count, x * .5 + y * .05);
    }
    return 0;
}
