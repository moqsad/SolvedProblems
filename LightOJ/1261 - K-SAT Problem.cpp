#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, cnt, i, j, x, n, m, k, num[35][35], ans[35], p;
    char arr[5];
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d", &n, &m, &k);
        memset(num, -1, sizeof(num));
        memset(ans, 0, sizeof(ans));
        for(i = 1; i <= n; ++i)
        {
            for(j = 1; j <= k; ++j)
            {
                scanf("%s", arr);
                if(arr[0] == '+')
                {
                    x = arr[1] - 48;
                    if(arr[2] != '\0')
                        x = x * 10 + arr[2] - 48;
                    if(num[i][x] == 0 || num[i][x] == 10)
                        num[i][x] = 10;
                    else
                        num[i][x] = 1;
                }

                else
                {
                    x = arr[1] - 48;
                    if(arr[2] != '\0')
                        x = x * 10 + arr[2] - 48;
                    if(num[i][x] == 1 || num[i][x] == 10)
                        num[i][x] = 10;
                    else
                        num[i][x] = 0;
                }
            }
        }

        scanf("%d", &p);
        for(i = 1; i <= p; ++i)
        {
            scanf("%d", &x);
            ans[x] = 1;
        }

        for(i = 1; i <= n; ++i)
        {
            for(j = 1; j <= m; ++j)
            {
                if(num[i][j] == 10 ||  num[i][j] == ans[j])
                    break;
            }

            if(j > m)
            {
//                printf("%d+++++++++\n", i);
                printf("Case %d: No\n", cnt);
                break;
            }
        }

        if(j <= m)
            printf("Case %d: Yes\n", cnt);
    }
    return 0;
}
