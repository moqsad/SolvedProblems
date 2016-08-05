#include <stdio.h>
int main()
{
    int count, arr[30], i, n, j, temp, k;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        if(n == 1)
            printf("Discarded cards:\nRemaining card: 1\n");
        else
        {
            j = 0;
            printf("Discarded cards: 1");
            for(i = 1; i < n; ++i)
            {
                if(i % 2 == 1)
                {
                    arr[j] = i + 1;
                    ++j;
                }
                else
                    printf(", %d", i + 1);
            }
            if(i % 2 == 1)
            {
                temp = arr[0];
                k = j;
                for(j = 1; j < k; ++j)
                    arr[j - 1] = arr[j];
                arr[j - 1] = 2;
            }
            k = j;
            j = 0;
            while(j < k - 1)
            {
                printf(", %d", arr[j]);
                if(j < k - 1)
                    temp = arr[j + 1];
                for(i = j + 1; i < k - 1; ++i)
                    arr[i] = arr[i + 1];
                arr[i] = temp;
                ++j;
            }
            printf("\nRemaining card: %d\n", arr[j]);
        }
    }
    return 0;
}
