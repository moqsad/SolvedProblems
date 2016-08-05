#include <cstdio>

int arr[35];

int main()
{
    int i, j, m, n, p;
    while(scanf("%d %d", &arr[0], &m) == 2)
    {
        p = 1;
        if(m == 0 || m == 1 || arr[0] == 0 || arr[0] == 1)
            p = 0;
        else
        {
            i = 0;
            while(arr[i] > 1)
            {
                if(arr[i] % m > 0)
                {
                    p = 0;
                    break;
                }
                ++i;
                arr[i] = arr[i - 1] / m;
            }
        }
        if(p == 0)
            printf("Boring!\n");
        else
        {
            printf("%d", arr[0]);
            for(j = 1; j <= i; ++j)
                printf(" %d", arr[j]);
            printf("\n");
        }
    }
    return 0;
}
