#include <stdio.h>
int main()
{
    int t, n, p, q, arr[35], cnt, i, sum;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d", &n, &p, &q);
        sum = 0;
        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &arr[i]);
        }
      for(i = 1; i <= n; ++i)
        {
            sum += arr[i];
            if(sum > q || i > p)
            break;
        }
        printf("Case %d: %d\n", cnt, i);
    }
    return 0;
}
