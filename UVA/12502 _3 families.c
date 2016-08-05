#include <stdio.h>
int main()
{
    int n, a, b, c, count, ans;
    float p, q, r, x;
    scanf("%d", &n);
    for(count = 1; count <= n; ++count)
    {
        scanf("%d %d %d", &a, &b, &c);
        p = a, q = b, r = c;
        x = (p + q) / 3;
        p = p - x;
        q = q - x;
        p = p / (p + q) * r;
        printf("%.0f\n", p);
    }
    return 0;
}
