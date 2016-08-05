#include <stdio.h>
#include <string.h>
int main()
{
    int count, a, b, c, i = 0, j;
    char arr[20], ch1, ch2;
    while(scanf("%d %c %d %c %s", &a, &ch1, &b, &ch2, arr) == 5)
    {
    if(arr[0] == '?' & strlen(arr) == 1)
        ;
    else
    {
        c = arr[0] - 48;
        for(j = 1; j < strlen(arr); ++j)
        {
            c *= 10;
            c += (arr[j] - 48);
        }
        if(ch1 == '+' && a + b == c)
            ++i;
        else if(a - b == c)
            ++i;
    }
    }
    printf("%d\n", i);
    return 0;
}
