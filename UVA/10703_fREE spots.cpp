#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int wi, h, n, cnt, a, b, c, d, w, x, y, z, i, j;
    while(scanf("%d %d %d", &wi, &h, &n) == 3)
    {
        if(wi == 0 && h == 0 && n == 0)
            break;
        ++h;
        ++wi;
        int arr[h][wi];
        memset(arr,0,sizeof(arr));
        for(cnt = 0; cnt < n; ++cnt)
        {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            w = (a <= c) ? a : c;
            x = (a >= c) ? a : c;
            y = (b <= d) ? b : d;
            z = (b >= d) ? b : d;
            for(i = y; i <= z; ++i)
                for(j = w; j <= x; ++j)
                {
                    arr[i][j] = 1;
                }
        }
        cnt = 0;
        for(i = 1; i < h; ++i)
            for(j = 1; j < wi; ++j)
                if(arr[i][j] == 0)
                    ++cnt;
        if(cnt > 1)
            printf("There are %d empty spots.\n", cnt);
        else if(cnt == 1)
            printf("There is one empty spot.\n");
        else
            printf("There is no empty spots.\n");
    }
    return 0;
}
