#include <cstdio>
#include <iostream>
using namespace  std;

int ans[22000], temp[22000];

int main()
{
    int t, cnt, i, j, need_to_make, n, x, y;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &need_to_make);
        scanf("%d", &n);

        temp[0] = 0;
        for(i = 1; i <= 20000; ++i)
        {
            ans[i] = 1000000000;
            temp[i] = 1000000000;
        }

        for(i = 0; i < n; ++i)
        {
            scanf("%d", &x);
            for(j = x; j <= 20000; ++j)
            {
                y = temp[j - x] + 1;
                if(y < ans[j])
                    ans[j] = y;
            }

            for(j = 1; j <= 20000; ++j)
                temp[j] = ans[j];
        }

        for(i = need_to_make; i <= 20000; ++i)
            if(ans[i] < 1000000000)
            {
                printf("%d %d\n", i, ans[i]);
                break;
            }
    }
    return 0;
}
