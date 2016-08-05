#include <cstdio>
#include <cstring>
#include  <iostream>
using namespace std;

char store[26000], arr[500000];

int ans[26000];

int main()
{
    int p, i, j, x, y;
    ans[25500] = 1;
    for(i = 25499; i >= 0; --i)
    {
        ans[i] = (ans[i + 1] * 2) % 131071;
//        printf("%d___\n", ans[i]);
    }

    p = 0;
    j = 0;
    while(gets(arr))
    {
        x = strlen(arr);
        for(i = 0; i < x; ++i)
        {
            if(arr[i] == '0' || arr[i] == '1')
                store[j++] = arr[i];

            else if(arr[i] == '#')
            {
                p = 1;
                break;
            }
        }

        y = 0;
        x = 25500;

        if(p == 1)
        {
            for(i = j - 1; i >= 0; --i)
            {
                if(store[i] == '1')
                    y += ans[x];
//                printf("%d %d+++++++\n", x, ans[x]);
                --x;
            }
//            printf("%d_____\n", x);
            y = y % 131071;

            if(y == 0)
                printf("YES\n");
            else
                printf("NO\n");
            p = 0;
            j = 0;
        }
    }
    return 0;
}
