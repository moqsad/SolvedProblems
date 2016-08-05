#include <cstdio>
#include <cstring>
#include <cctype>

char arr[300];

int main()
{
    long long t, cnt, i, x, d, ans;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s %lld", arr, &d);
        if(d < 0)
            d = - d;
        ans = 0;
        if(isdigit(arr[0]))
        {
            x = strlen(arr);
            for(i = 0; i < x; ++i)
                ans = (ans * 10 + arr[i] - 48) % d;
        }
        else
        {
            x = strlen(arr);
            for(i = 1; i < x; ++i)
                ans = (ans * 10 + arr[i] - 48) % d;
        }
        if(ans == 0)
            printf("Case %lld: divisible\n", cnt);
        else
            printf("Case %lld: not divisible\n", cnt);
    }
    return 0;
}
