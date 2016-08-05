#include <cstdio>
#include <cmath>
int main()
{
    int n, k;
    double ans, x, y, i;
    while(scanf("%d %d", &n, &k) == 2)
    {
        ans = 0;
        if(k > n - k)
        {
            x = k + 1;
            y = n - k;
        }
        else
        {
            x = n - k + 1;
            y = k;
        }
        if(k == n)
        {
            printf("1\n");
        }
        else
        {
            i = 2;
            ans += log10(x++);
            while(i <= y)
            {
                ans += log10(x++/i++);
//            printf("%d %d %lf\n", x - 1, i - 1, ans);
            }
            printf("%d\n", (int)ans + 1);
        }
    }
    return 0;
}
