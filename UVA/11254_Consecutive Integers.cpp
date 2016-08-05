#include <cstdio>
#include <cmath>

int main()
{
    int sum, i, x, y;
    double a, n, b;
    while(scanf("%d", &sum) == 1)
    {
        if(sum == -1)
            break;
        x = 2 * sum;
        y = sqrt(x);
        for(i = y; i >= 1; --i)
        {
            n = i;
            a = (x + n - n * n) / (2 * n);
            b = (int) a;
            if(a == b)
                break;
        }
        x = a;
        y = a + (i - 1);
        printf("%d = %d + ... + %d\n", sum, x, y);
    }
    return 0;
}
