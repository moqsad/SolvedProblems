#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int count, n, i, j, num[26], x, y;
    char letter[] = "abcdefghijklmnopqrstuvwxyz", arr[250];
    scanf("%d", &n);
    getchar();
    for(count = 1; count <= n; ++count)
    {
        for(i = 0; i < 26; ++i)
            num[i] = 0;
        gets(arr);
        for(i = 0; i < strlen(arr); ++i)
            for(j = 0; j < 26; ++j)
                if(tolower(arr[i]) == letter[j])
                {
                    ++num[j];
                    break;
                }
                x = 0;
        for(i = 0; i < 26; ++i)
        {
            if(num[i] > num[x])
            x = i;
        }
        printf("%c", letter[x]);
        y = num[x];
        num[x] = 0;
        for(i = 0; i < 26; ++i)
        {
            if(num[i] == y)
            printf("%c", letter[i]);
        }
        printf("\n");
    }
    return 0;
}
