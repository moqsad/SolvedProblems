#include <stdio.h>
int arr[1000001];

int main()
{
    int x, y, i, j;
    for(i = 1; i < 1000000; ++i)
    {
        x = i;
        y = x;
        while(x / 10 > 0)
        {
            y += x % 10;
            x /= 10;
        }
        y += x;
        arr[y] = 1;
    }
   for(i = 1; i < 1000001; ++i)
        if(arr[i] == 0)
       printf("%d\n", i);
    return 0;
}
