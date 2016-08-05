#include <stdio.h>
#include <stdlib.h>

int cmpfunc1 (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int cmpfunc2 (const void * a, const void * b)
{
    return ( *(int*)b - *(int*)a );
}

int main()
{
    int n, count, i, d, r, sum;
    while(1)
    {
        scanf("%d %d %d", &n, &d, &r);
        if(n == 0 && d == 0 && r == 0)
            break;
        sum = 0;
        int mor[n], eve[n];
        for(count = 0; count < n; ++count)
            scanf("%d", &mor[count]);
        for(count = 0; count < n; ++count)
            scanf("%d", &eve[count]);

        qsort(mor, n, sizeof(int), cmpfunc1);
        qsort(eve, n, sizeof(int), cmpfunc2);

        for(count = 0; count < n; ++count)
        {
            i = mor[count] + eve[count];
            if(i > d)
            {
                sum += (i - d) * r;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
