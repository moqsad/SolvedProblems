#include <stdio.h>
#include <math.h>
int main()
{
    double n, ans;
    int t, count;
    scanf("%d", &t);
    for(count = 1; count <= t; ++count)
    {
        scanf("%lf", &n);
        ans = (- 1 + sqrt(1 + 8 * n)) / 2;
        printf("%.lf\n", floor(ans));
    }
    return 0;
}
