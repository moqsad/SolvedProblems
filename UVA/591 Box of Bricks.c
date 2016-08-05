#include <stdio.h>
int main()
{
    int n, count, k, h[100], ave, sum, i = 0;
    while(1){
        scanf("%d", &n);
        if(n == 0)
        break;
        ++i;
        sum = 0;
        for(count = 0; count < n; ++count)
        {
            scanf("%d", &h[count]);
            sum += h[count];

        }
        ave = sum / n;
        k = 0;
        for(count = 0; count < n; ++count)
        if(h[count] > ave)
        k += h[count] - ave;
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", i, k);
    }
    return 0;
}
