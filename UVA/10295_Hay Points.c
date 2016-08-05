#include <stdio.h>
int main()
{
    int num[1050], a, b, sum, cnt, i, j;
    char arr[1050][20], letter[40];
    scanf("%d %d", &a, &b);
    for(cnt = 0; cnt < a; ++cnt)
    {
        scanf("%s %d", arr[cnt], &num[cnt]);
    }
    for(cnt = 0; cnt < b; ++cnt)
    {
        sum = 0;
        while(scanf("%s", letter) == 1)
        {
            if(letter[0] == '.')
                break;
            for(i = 0; i < a; ++i)
                if(strcmp(arr[i], letter) == 0)
                {
                    sum += num[i];
                    break;
                }
        }
        printf("%d\n", sum);
    }
    return 0;
}
