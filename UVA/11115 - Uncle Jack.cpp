#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int arr[30], ans[30], n, d, i, j, k, x;
    while(scanf("%d %d", &n, &d) == 2)
    {
        if(n == 0 && d == 0)
            break;
        if(d == 0)
            printf("1\n");
        else
        {
            x = n;
            i = 0;
            while(x > 0)
            {
                arr[i++] = x % 10;
                x /= 10;
            }
//        printf("_________%d\n", i);

            for(j = 1; j < d; ++j)
            {
                x = 0;
                for(k = 0; k < i; ++k)
                {
                    ans[k] = (arr[k] * n + x) % 10;
                    x = (arr[k] * n + x) / 10;
                }

                while(x > 0)
                {
                    ans[k++] = x % 10;
                    x = x / 10;
                }
//            printf("++++++++++%d\n", k);
                for(i = 0; i < k; ++i)
                    arr[i] = ans[i];
            }

            for(k = i - 1; k >= 0; --k)
                printf("%d", arr[k]);
            printf("\n");
        }
    }
    return 0;
}
