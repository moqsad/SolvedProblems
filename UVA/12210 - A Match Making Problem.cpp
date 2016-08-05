#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int b, s, i, num, a, ans, cnt = 0;
    while(scanf("%d %d", &b, &s) == 2)
    {
        if(b == 0 && s == 0)
            break;

        num = 100;

        if(b > s)
        {
            for(i = 0; i < b; ++i)
            {
                scanf("%d", &a);
                if(a < num)
                    num = a;
            }
            for(i = 0; i < s; ++i)
                scanf("%d", &a);
            printf("Case %d: %d %d\n", ++cnt, b - s, num);
        }

        else
        {
            for(i = 0; i < b; ++i)
                scanf("%d", &a);
            for(i = 0; i < s; ++i)
                scanf("%d", &a);
            printf("Case %d: 0\n", ++cnt);
        }


    }
    return 0;
}
