#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[100002][12][3], p, x, sz;
char a[12];

void func(int pos, int index)
{
    int data = a[index] - '0';
    if(index == x)
    {
        if(arr[pos][data][0] == -1)
        {
            if(arr[pos][data][1] == 0)
                p = 0;
            else
                arr[pos][data][1] = 0;
            return ;
        }
        p = 0;
        return ;
    }

    if(arr[pos][data][1] == -1)
    {
        if(arr[pos][data][0] == -1)
        {
            arr[pos][data][0] = ++sz;
            func(sz, index + 1);
        }

        else
            func(arr[pos][data][0], index + 1);
        return ;
    }
    p = 0;
    return ;
}

int main()
{
    int t, cnt, i, j, n;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        memset(arr, -1, sizeof(arr));
        p = 1;
        sz = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%s", a);
            if(p == 1)
            {
                x = strlen(a) - 1;
                func(0, 0);
            }
        }

//        if(p == 1)
//            printf("YES\n");
//        else
//            printf("NO\n");

        if(p == 1)
            printf("Case %d: YES\n", cnt);
        else
            printf("Case %d: NO\n", cnt);
    }
    return 0;
}
