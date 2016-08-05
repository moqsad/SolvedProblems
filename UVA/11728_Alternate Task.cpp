#include <cstdio>

int ans[1010];
bool done[1010];

int main()
{
    int cnt, i, sum, s, x;
    ans[1] = 1;
    for(cnt = 1000; cnt > 1; --cnt)
    {
        x = cnt / 2;
        sum = 1 + cnt;
        for(i = 2; i <= x; ++i)
        {
            if(cnt % i == 0)
                sum += i;
        }
        if(sum <= 1000)
        {
            if(done[sum] == 0)
            {
                done[sum] = 1;
                ans[sum] = cnt;
            }
        }
    }
    cnt = 0;
    while(scanf("%d", &s) == 1)
    {
        if(s == 0)
            break;
        if(ans[s] > 0)
            printf("Case %d: %d\n", ++cnt, ans[s]);
        else
            printf("Case %d: -1\n", ++cnt);
    }
    return 0;
}
