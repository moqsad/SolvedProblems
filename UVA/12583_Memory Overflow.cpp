#include <cstdio>

int main()
{
    int t, cnt, ans, i, j, n, k, x;
    char arr[600], ch;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        ans = 0;
        scanf("%d %d %s", &n, &k, arr);
        for(i = 0; i < n; ++i)
        {
            ch = arr[i];
            x = i + k;
            if(x >= n)
                x = n - 1;
            for(j = i + 1; j <= x; ++j)
            {
                if(arr[j] == ch)
                {
                    ++ans;
                    break;
                }
            }
        }
        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}
