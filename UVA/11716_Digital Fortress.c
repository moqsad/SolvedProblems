#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    int a, b, cnt, i, j, t;
    char arr[10500];
    scanf("%d\n", &t);
    for(j = 0; j < t; ++j)
    {
        gets(arr);
        a = strlen(arr);
        b = sqrt(a);
        if(b * b != a)
            printf("INVALID\n");
        else
        {
            for(i = 0; i < b; ++i)
            for(cnt = 0 + i; cnt < a; cnt += b)
                printf("%c", arr[cnt]);
            printf("\n");
        }
    }
    return 0;
}
