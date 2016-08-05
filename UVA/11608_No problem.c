#include <stdio.h>
int main()
{
    int arr[25], count, x, i = 0;
    while(1)
    {
        scanf("%d", &arr[0]);
        if(arr[0] < 0)
            break;
        ++i;
        for(count = 1; count <= 24; ++count)
        {
            scanf("%d", &arr[count]);
        }
        x = arr[0];
        printf("Case %d:\n", i);
        for(count = 13; count < 24; ++count)
        {
            if(x >= arr[count])
            {
                printf("No problem! :D\n");
                x += arr[count % 12] - arr[count];
            }
            else
            {
                printf("No problem. :(\n");
                x += arr[count % 12];
            }
        }
        if(x >= arr[count])
            printf("No problem! :D\n");
        else
            printf("No problem. :(\n");
    }
    return 0;
}
