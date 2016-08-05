#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

char arr[25][25];

int func(int r, int c, )

int main()
{
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &r, &c);
        for(i = 0; i < r; ++i)
            scanf("%s", arr[i]);

        for(i = 0; i < r; ++i)
        {
            for(j = 0; j < c; ++j)
            {
                if(arr[i][j] == 'x')
                    break;
            }
            if(j < c)
                break;
        }

        printf("Case %d: %d\n", cnt, func(i, j, ));

    }
    return 0;
}
