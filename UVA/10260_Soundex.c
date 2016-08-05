#include <stdio.h>
#include <string.h>
int main()
{
    int count, i, j, p;
    char arr1[100], arr2[] = "BFPVCGJKQSXZDTLMNR", ans[20];
    while(scanf("%s", arr1) == 1)
    {
        count = 0;
        j = 0;
        while(arr1[count] != '\0')
        {
            p = 1;
            for(i = 0; i < strlen(arr2); ++i)
                if(arr1[count] == arr2[i])
                {
                    p = 0;
                    if(i >= 0 && i <= 3)
                        ans[count] = '1';
                    else if(i > 3 && i <= 11)
                        ans[count] = '2';
                    else if(i > 11 && i <= 13)
                        ans[count] = '3';
                    else if(i == 14)
                        ans[count] = '4';
                    else if(i > 14 && i <= 16)
                        ans[count] = '5';
                    else
                        ans[count] = '6';
                }
            if(p == 1)
            ans[count] = '0';
            ++count;
        }
        ans[count] = '\0';
        i = 0;
        for(j = 0; j < count; ++j)
            if(ans[j] == ans[j + 1])
            {
                while(ans[j] == ans[j + 1] && ans[j] != '0')
                {
                    ++j;
                    if(ans[j] != ans[j + 1])
                    {
                     arr1[i] = ans[j];
                     ++i;
                    }
                }
            }
            else if(ans[j] != '0')
            {
            arr1[i] = ans[j];
            ++i;
            }
            arr1[i] = '\0';
            printf("%s\n", arr1);
    }
    return 0;
}
