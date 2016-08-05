#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, cnt, x, ans, i, n;
    char ch;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        ans = 0;
        x = 0;
        for(i = 1; i <= n; ++i)
        {
            scanf(" %c", &ch);
            if(ch != 'W')
                ++x;
            else
                x = 0;
            if(x == 3)
            {
                ans = i;
                break;
            }
        }

        for(i = i + 1; i <= n; ++i)
            scanf(" %c", &ch);
        if(ans == 0)
            printf("Case %d: Yay! Mighty Rafa persists!\n", cnt);
        else
            printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}
