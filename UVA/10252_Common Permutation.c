#include <stdio.h>
#include <string.h>
int main()
{
    int cnt, i, j;
    char arr1[1050], arr2[1050], ans[1050], temp;
    while(gets(arr1) && gets(arr2))
    {
        j = 0;
        for(cnt = 0; cnt < strlen(arr1); ++cnt)
        for(i = 0; i < strlen(arr2); ++i)
        {
            if(arr1[cnt] == arr2[i])
            {
                ans[j] = arr1[cnt];
                arr2[i] = '*';
                ++j;
                break;
            }
        }
        cnt = j;
        for(i = 0; i < cnt - 1; ++i)
        for(j = i + 1; j < cnt; ++j)
        {
            if(ans[j] < ans[i])
            {
                temp = ans[i];
                ans[i] = ans[j];
                ans[j] = temp;
            }
        }
        ans[j] = '\0';
        printf("%s\n", ans);
    }
    return 0;
}
