#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    int t,cnt, a, b, l, w, h, v, x, y, n, i;
    char arr[30], small[30], big[30];
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        x = 0;
        y = 1000000000;
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%s %d %d %d", arr, &l, &w, &h);
            v = l * w * h;
            if(v > x)
            {
                x = v;
                strcpy(big, arr);
            }
            if(v < y)
            {
                y = v;
                strcpy(small, arr);
            }
        }
        if(x != y)
            printf("Case %d: %s took chocolate from %s\n", cnt, big, small);
        else
            printf("Case %d: no thief\n", cnt);
    }
    return 0;
}
