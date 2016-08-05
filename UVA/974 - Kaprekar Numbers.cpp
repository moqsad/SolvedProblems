#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

bool arr[40010];

int main()
{
    int i, j, p, x, y, z, a, b, cnt, t;
    for(i = 2; i < 40001; ++i)
    {
        x = i * i;
        j = 10;
        p = 0;
        while(x / j > 0)
        {
            y = x % j;
            z = x / j;
            if(y + z == i && y > 0)
            {
                p = 1;
                break;
            }
            j *= 10;
        }
        if(p == 1)
            arr[i] = 1;
    }

    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &a, &b);
        printf("case #%d\n", cnt);
        p = 0;
        for(i = a; i <= b; ++i)
            if(arr[i] == 1)
            {
                printf("%d\n", i);
                p = 1;
            }
        if(p == 0)
            printf("no kaprekar numbers\n");
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
