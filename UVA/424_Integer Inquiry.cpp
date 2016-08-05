#include <cstdio>
#include <cstring>
char arr[110][110], ans[120];

int main()
{
    long long i = 0, j, k, cnt, x = 0, y, z, c;
    memset(arr, '0', sizeof(arr));
    while(scanf("%s", arr[i]) == 1)
    {
        if(strlen(arr[i]) == 1 && arr[i][0] == '0')
            break;
        if(strlen(arr[i]) > x)
            x = strlen(arr[i]);
        ++i;
    }
    k = 1;
    y = 0;
    for(j = x; j > 0; --j)
    {
        for(cnt = 0; cnt < i; ++cnt)
        {
            z = strlen(arr[cnt]) - k;
            if(z >= 0)
                y += arr[cnt][z] - 48;
        }
        ans[k] = y % 10 + 48;
        y = y / 10;
        ++k;
    }
    if(y > 0)
    printf("%lld", y);
    for(i = x; i > 0; --i)
        printf("%c", ans[i]);
    printf("\n");
    return 0;
}
