#include <cstdio>
#include <cmath>

//long long p[2], a[2];
long long ans[20];

int main()
{
    long long i, n, x;
    ans[2] = ans[3] = ans[5] = ans[7] = ans[13] = ans[17] = 1;
    scanf("%lld", &n);
    for(i = 1; i < n; ++i)
    {
        scanf("%lld ,", &x);
        if(x < 18)
        {
            if(ans[x] == 1)
                printf("Yes\n");
            else
                printf("No\n");
        }
        else
            printf("No\n");
    }
    scanf("%lld", &x);
    if(x < 18)
    {
        if(ans[x] == 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    else
        printf("No\n");
    return 0;
}
