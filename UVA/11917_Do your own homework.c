#include <stdio.h>
#include <string.h>
int main()
{
    int t, n, d, i, p, num[110], cnt;
    char arr[110][30], letter[30];
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%s %d", arr[i], &num[i]);
        }
        scanf("%d %s", &d, letter);
        p = 1;
        for(i = 0; i < n; ++i)
        {
            if(strcmp(arr[i], letter) == 0)
            {
                p = 0;
                if(num[i] <= d)
                    printf("Case %d: Yesss\n", cnt);
                else if(num[i] < d + 6)
                    printf("Case %d: Late\n", cnt);
                else
                    p = 1;
                break;
            }
        }
        if(p == 1)
            printf("Case %d: Do your own homework!\n", cnt);
    }
    return 0;
}
