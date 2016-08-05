#include <cstdio>
#include <cstring>

int main()
{
    int t, cnt, n, sum, i, a;
    char arr[10];
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        printf("Case %d:\n", cnt);
        sum = 0;
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%s", arr);
            if(strcmp(arr, "donate") == 0)
            {
                scanf("%d", &a);
                sum += a;
            }
            else
                printf("%d\n", sum);
        }
    }
    return 0;
}
