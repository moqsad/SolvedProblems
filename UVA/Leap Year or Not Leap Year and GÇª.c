#include <stdio.h>
#include <string.h>

char arr[100050];

int main()
{
    int cnt, x, i, y, p, j = 0, k;
    while(scanf("%s", arr) == 1)
    {
        x = strlen(arr);
        ++j;
        if(j > 1)
            printf("\n");
        y = arr[x - 4] - 48;
        for(i = x - 3; i < x; ++i)
        {
            y = y * 10 + arr[i] - 48;
        }
        p = 0;
        k = 0;
        if((y % 4 == 0 && y % 100 > 0) || y % 400 == 0)
        {
            k = 5;
            printf("This is leap year.\n");
            y = arr[0] - 48;
            for(i = 1; i < x; ++i)
            {
                y = y * 10 + arr[i] - 48;
                y = y % 55;
            }
            if(y == 0)
                p = 1;
        }
        y = arr[0] - 48;
        for(i = 1; i < x; ++i)
        {
            y = y * 10 + arr[i] - 48;
            y = y % 15;
        }
        if(y == 0)
        {
            k = 5;
            printf("This is huluculu festival year.\n");
        }
        if(p == 1)
            printf("This is bulukulu festival year.\n");
        if(k == 0)
            printf("This is an ordinary year.\n");
    }
    return 0;
}

