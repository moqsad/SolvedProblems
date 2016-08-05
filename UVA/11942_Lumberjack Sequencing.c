#include <stdio.h>
int main()
{
    int arr[10], t, diff, count, i;
    scanf("%d", &t);
    printf("Lumberjacks:\n");
    for(count = 1; count <= t; ++count)
    {
        for(i = 0; i < 10; ++i)
        {
            scanf("%d", &arr[i]);
        }
        for(i = 1; i < 10; ++i)
            if(!(arr[i] >= arr[i - 1]))
            {
                break;
            }
        if(i != 10)
        {
            for(i = 1; i < 10; ++i)
                if(!(arr[i] <= arr[i - 1]))
                {
                    break;
                }
        }
        if(i == 10)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return 0;
}
