#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int fc, rc, i, j, k;
    double a, fc_t[15], arr[110], max;
    while(scanf("%d", &fc) == 1)
    {
        if(fc == 0)
            break ;
        scanf("%d", &rc);
        for(i = 0; i < fc; ++i)
            scanf("%lf", &fc_t[i]);
        k = 0;
        for(i = 0; i < rc; ++i)
        {
            scanf("%lf", &a);
            for(j = 0; j < fc; ++j)
                arr[k++] = fc_t[j] / a;
        }

        max = 0;
        sort(arr, arr + k);
        for(i = 1; i < k; ++i)
        {
            a = arr[i] / arr[i - 1];
            if(a > max)
                max = a;
        }
        printf("%.2lf\n", max);
    }
    return 0;
}
