#include <cstdio>
#include <cstring>

int main()
{
    char arr[90];
    int x, i, j, t, cnt, ans;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s", arr);
        x = strlen(arr);
        ans = 0;
        j = 0;
        for(i = 0; i < x; ++i)
        {
            if(arr[i] == 'O')
                ++j;
            else
                j = 0;
            ans += j;
        }
        printf("%d\n", ans);
    }
    return 0;
}
