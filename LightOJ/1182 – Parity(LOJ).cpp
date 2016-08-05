#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, cnt, p, i, j, x, y, n;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        x = 0;
        while(n > 0)
        {
            if(n % 2 == 1)
                ++x;
            n = n / 2;
        }
        if(x % 2 == 1)
            printf("Case %d: odd\n", cnt);
        else
            printf("Case %d: even\n", cnt);
    }
    return 0;
}
