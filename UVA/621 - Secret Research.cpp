#include <cstdio>
#include <cstring>

char arr[10010];

int main()
{
    int t, cnt, x;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%s", arr);
        x = strlen(arr);
        if(strcmp(arr, "1") == 0 || strcmp(arr, "4") == 0 || strcmp(arr, "78") == 0)
            printf("+\n");
        else if(arr[x - 1] == '5' && arr[x - 2] == '3')
            printf("-\n");
        else if(arr[0] == '1' && arr[1] == '9' && arr[2] == '0')
            printf("?\n");
        else
            printf("*\n");
    }
    return 0;
}
