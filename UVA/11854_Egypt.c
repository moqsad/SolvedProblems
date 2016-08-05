#include <stdio.h>
int main()
{
    int arr[3], ans, count, i, temp;
    while(1)
    {
        scanf("%d %d %d", &arr[0], &arr[1], &arr[2]);
        if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
        break;
        for(count = 0; count < 2; ++count)
        for(i = count + 1; i < 3; ++i)
            if(arr[i] < arr[count])
            {
                temp = arr[count];
                arr[count] = arr[i];
                arr[i] = temp;
            }
            if(arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1])
            printf("right\n");
            else
            printf("wrong\n");
    }
    return 0;
}
