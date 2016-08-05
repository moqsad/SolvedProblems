#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int arr[60];

int main()
{
    int cnt, i, j, k, l, m, n, t, det = 0, a, b, c, d, e, f;
    while(scanf("%d", &t) == 1)
    {
        if(t == 0)
            break;
        if(det > 0)
            printf("\n");
        for(cnt = 0; cnt < t; ++cnt)
            scanf("%d", &arr[cnt]);
            a = t - 5;
            b = t - 4;
            c = t - 3;
            d = t - 2;
            e = t - 1;
            f = t;
        for(i = 0; i < a; ++i)
            for(j = i + 1; j < b; ++j)
                for(k = j + 1; k < c; ++k)
                    for(l = k + 1; l < d; ++l)
                        for(m = l + 1; m < e; ++m)
                            for(n = m + 1; n < f; ++n)
                                printf("%d %d %d %d %d %d\n", arr[i], arr[j], arr[k], arr[l], arr[m], arr[n]);
    ++det;
    }
    return 0;
}
