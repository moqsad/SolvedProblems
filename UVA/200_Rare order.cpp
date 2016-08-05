#include <cstdio>
#include <cstring>

char arr[10010][25];

int main()
{
    int x, total = 0, i = 0, j, k;
    int ans[95];
    memset(ans, 0, sizeof(ans));
    memset(arr, '0', sizeof(arr));
    ans['0'] = 1;
    ans['\0'] = 1;
    while(scanf("%s", &arr[i]) == 1)
    {
        if(arr[i][0] == '#')
            break;
        x = strlen(arr[i]);
        if(x > total)
            total = x;
        ++i;
    }
    for(k = 0; k < total; ++k)
    {
        for(j = 0; j < i; ++j)
        {
            if(ans[arr[j][k]] == 0)
            {
                printf("%c", arr[j][k]);
                ans[arr[j][k]] = 1;
            }
        }
    }
    printf("\n");
    return 0;
}
