#include <stdio.h>
#include <string.h>
int main()
{
    int count, n, k, i;
    char arr[50][150], letter[150][150];
    scanf("%d", &n);
    getchar();
    for(count = 0; count < 2 * n; ++count)
    {
        gets(arr[count]);
    }
    scanf("%d", &k);
    getchar();
    for(count = 0; count < k; ++count)
    {
        gets(letter[count]);
    }
    for(count = 0; count < k; ++count)
    {
        for(i = 0; i < 2 * n; i += 2)
        {
            if(strcmp(letter[count], arr[i]) == 0)
            {
                printf("%s\n", arr[i + 1]);
                break;
            }
        }
    }
    return 0;
}
