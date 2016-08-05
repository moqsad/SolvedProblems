#include <stdio.h>
#include <math.h>
int main()
{
    int n, count, p, q, x[10], i, j, ans, m, det;
    while(scanf("%d", &n) == 1)
    {
        if(n == 1)
            printf("1 is not prime.\n");
        else if(n == 2)
            printf("2 is prime.\n");
        else
        {
            m = n;
            p = 1;
            det = 1;
            for(count = 2; count <= sqrt(n) + 1; ++count)
                if(n % count == 0)
                {
                    p = 0;
                    break;
                }
            if(p == 1)
            {
                i = 0;
                while(n != 0)
                {
                    x[i] = n % 10;
                    n /= 10;
                    ++i;
                }
                ans = x[0];
                for(j = 1; j < i; ++j)
                    ans = ans * 10 + x[j];
                if(ans == m)
                {
                    printf("%d is prime.\n", m);
                    det = 0;
                }
                q = 1;
                for(count = 2; count < sqrt(ans) + 1; ++count)
                    if(ans % count == 0)
                    {
                        q = 0;
                        break;
                    }
                if(q == 1 && det == 1)
                    printf("%d is emirp.\n", m);
                else if(det == 1)
                    printf("%d is prime.\n", m);
            }
            else if(det == 1)
                printf("%d is not prime.\n", m);
        }
    }
    return 0;
}
