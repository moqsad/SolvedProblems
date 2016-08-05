#include <cstdio>

int arr[110];

int main()
{
    int i, j, t, cnt, temp, ans, n;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        ans = 0;
        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
        }
        for(i = 1; i <= n; ++i)
        {
            for(j = 1; j <= n; j++)
            {
                if(arr[j] != j)
                {
                    temp = arr[arr[j]];
                    arr[arr[j]] = arr[j];
                    arr[j] = temp;
                    ++ans;
                    break;
                }
            }
            if(j > n)
                break;
        }
        printf("Case %d: %d\n", cnt, ans);
    }
    return 0;
}
