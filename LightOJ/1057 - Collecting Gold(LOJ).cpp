#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;

struct data
{
    int r, c;
};

data st[18], info;
int k, x, n, m, dp[18][65540];
char arr[25];

int func(int pre, int index)
{
    int i, min_ = 100000000, a, b;

    if(index == x)
    {
        a = abs(st[pre].r - st[0].r);
        b = abs(st[pre].c - st[0].c);
        min_ = max(a, b);
    }

    if(dp[pre][index] != -1)
        return dp[pre][index];

    for(i = 1; i < k; ++i)
    {
        if((index & (1 << i)) == 0)
        {
            a = abs(st[pre].r - st[i].r);
            b = abs(st[pre].c - st[i].c);
            min_ = min(min_, max(a, b) + func(i, index | (1 << i)));
        }
    }

    return dp[pre][index] = min_;
}

int main()
{
    int i, j, cnt, t;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        k = 1;
        x = 2;
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; ++i)
        {
            scanf("%s", arr);
            for(j = 0; j < m; ++j)
            {
                if(arr[j] == 'g')
                {
                    x *= 2;
                    info.r = i;
                    info.c = j;
                    st[k++] = info;
                }

                else if(arr[j] == 'x')
                {
                    info.r = i;
                    info.c = j;
                    st[0] = info;
                }
            }
        }

        memset(dp, -1, sizeof(dp));
        x -= 1;
        printf("Case %d: %d\n", cnt, func(0, 1));
    }
    return 0;
}
