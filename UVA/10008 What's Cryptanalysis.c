#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int n, count, ans[26], i, j, temp, x, y;
    char arr[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", input[150];
    scanf("%d", &n);
    getchar();
    for(j = 0; j < 26; ++j)
        ans[j] = 0;
    for(count = 1; count <= n; ++count)
    {
        gets(input);
        for(i = 0; i < strlen(input); ++i)
        {
            for(j = 0; j < 26; ++j)
                if(toupper(input[i]) == arr[j])
                    ++ans[j];
        }
    }
    for(i = 0; i < 26; ++i)
    {
        x = 0;
        for(j = 0; j < 26; ++j)
            if(ans[j] > ans[x])
                x = j;
        if(ans[x] == 0)
        break;
        else
        {
            printf("%c %d\n", arr[x], ans[x]);
            ans[x] = 0;
        }
    }
    return 0;
}
