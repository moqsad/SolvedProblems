#include <stdio.h>
#include <string.h>
int main()
{
    int count, i, ans, j, t, p;
    char arr[150], a1[] = "adgjmptw ", a2[] = "behknqux", a3[] = "cfilorvy";
    scanf("%d", &t);
    getchar();
    for(j = 1; j <= t; ++j)
    {
        gets(arr);
        ans = 0;
        for(count = 0; arr[count] != '\0'; ++count)
        {
            while(1)
            {
                p = 0;
                for(i = 0; i < strlen(a1); ++i)
                    if(arr[count] == a1[i])
                    {
                        p = 1;
                        ans += 1;
                        break;
                    }
                    if(p == 1)
                        break;
                for(i = 0; i < strlen(a2); ++i)
                    if(arr[count] == a2[i])
                    {
                        p = 1;
                        ans += 2;
                        break;
                    }
                    if(p == 1)
                        break;
                if(arr[count] == 's' || arr[count] == 'z')
                    ans += 4;
                else
                    ans += 3;
                break;
            }
        }
        printf("Case #%d: %d\n", j, ans);
    }
    return 0;
}

