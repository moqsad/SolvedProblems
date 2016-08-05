#include <stdio.h>
#include <string.h>
int main()
{
    int count, i, x, p, q;
    char arr1[120000], arr2[120000];
    while(scanf("%s %s", arr1, arr2) == 2)
    {
        x = 0;
        p = 0;
        for(count = 0; count < strlen(arr1); ++count)
        {
            q = 0;
            for(i = x; i < strlen(arr2); ++i)
            {
                if(arr1[count] == arr2[i])
                {
                    x = i + 1;
                    ++p;
                    q = 1;
                    break;
                }
            }
            if(q == 0)
                break;
            else if(p == strlen(arr1))
            {
                printf("Yes\n");
                break;
            }
        }
        if(p != strlen(arr1))
            printf("No\n");
    }
    return 0;
}
