#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char arr[100];

int main()
{
    int t, cnt, p, i, j, x, n;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s", arr);
        x = strlen(arr);
        n = x / 2;
        j = x - 1;
        p = 1;
        for(i = 0; i < n; ++i)
        {
            if(arr[i] != arr[j])
            {
                p = 0;
                break;
            }
            --j;
        }
        if(p == 0)
            printf("Case %d: No\n", cnt);
        else
            printf("Case %d: Yes\n", cnt);
    }
    return 0;
}
