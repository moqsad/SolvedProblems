#include <stdio.h>
int main()
{
    int count, i, num[6], j, x, t;
    char arr[600], letter[] = "AGIMRT";
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        for(i = 0; i < 6; ++i)
            num[i] = 0;
        scanf("%s", &arr);
        i = 0;
        while(arr[i] != '\0')
        {
            for(j = 0; j < 6; ++j)
                if(arr[i] == letter[j])
                {
                    ++num[j];
                    break;
                }
                ++i;
        }
        num[0] /= 3;
        num[4] /= 2;
        x = num[0];
        for(i = 1; i < 6; ++i)
            if(num[i] < x)
                x = num[i];
        printf("%d\n", x);
    }
    return 0;
}
