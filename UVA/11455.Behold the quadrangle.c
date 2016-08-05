#include <stdio.h>
int main()
{
    int n, count, arr[4], temp, i, j;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
    for(i = 0; i < 4; ++i)
        scanf("%d", &arr[i]);
    for(i = 0; i < 3; ++i)
        for(j = i + 1; j < 4; ++j)
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            if(arr[0] == arr[1] && arr[0] == arr[2] && arr[0] == arr[3])
            printf("square\n");
            else if(arr[0] == arr[1] && arr[2] == arr[3])
            printf("rectangle\n");
            else if(arr[0] < arr[1] + arr[2] + arr[3])
            printf("quadrangle\n");
            else
            printf("banana\n");
    }
return 0;
}
