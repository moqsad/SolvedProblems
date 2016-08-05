#include <stdio.h>
#include <string.h>
int main()
{
    int n, count, i, det;
    char arr1[21], arr2[21], x, y;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        det = 1;
        scanf("%s %s", arr1, arr2);
        if(strlen(arr1) != strlen(arr2))
        {
            printf("No\n");
            det = 0;
        }
        else
            for(i = 0; i < strlen(arr1); ++i)
            {
                x = arr1[i];
                y = arr2[i];
                if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
                {
                    if(!(y == 'a' || y == 'e' || y == 'i' || y == 'o' || y == 'u' || y == '0'))
                    {
                        printf("No\n");
                        det = 0;
                        break;
                    }
                }
                else if(arr1[i] != arr2[i])
                {
                    printf("No\n");
                    det = 0;
                    break;
                }
            }
        if(det == 1)
            printf("Yes\n");
    }
    return 0;
}
