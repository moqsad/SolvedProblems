#include <stdio.h>
#include <string.h>
int main()
{
    int cnt, i, j, p, q, n;
    char arr[150];
    scanf("%d", &n);
    getchar();
    for(cnt = 1; cnt <= n; ++cnt)
    {
        gets(arr);
        i = 0;
        p = 1;
        while(arr[i] != '\0')
        {
            if(arr[i] == '(' || arr[i] == '[')
            {
                q = 0;
                if(arr[i] == '(')
                {
                    for(j = i + 1; j < strlen(arr); j += 2)
                    {
                        if(arr[j] == ')')
                        {
                            arr[j] = '*';
                            q = 1;
                            break;
                        }
                    }
                    if(q == 0)
                        p = 0;
                }
                else
                {
                    for(j = i + 1; j < strlen(arr); j += 2)
                    {
                        if(arr[j] == ']')
                        {
                            arr[j] = '*';
                            q = 1;
                            break;
                        }
                    }
                    if(q == 0)
                        p = 0;
                }
            }
            else if(arr[i] == ')' || arr[i] == ']')
            {
                p = 0;
                break;
            }
            ++i;
        }
        if(p == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
