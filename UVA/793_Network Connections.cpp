#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

int par[900000];
char arr[50], mid[25];

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

int main()
{
    int i, j, t, n, cnt, yes, no, x, y;
    scanf("%d\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        yes = 0;
        no = 0;
        scanf("%d\n", &n);
        for(i = 1; i <= n; ++i)
        {
            par[i] = i;
        }
        while(gets(arr))
        {
            if(arr[0] == '\0')
                break;
            if(arr[0] == 'c')
            {
                i = 2;
                j = 0;
                while(arr[i] != ' ')
                    mid[j++] = arr[i++];
                mid[j] = '\0';
                x = func(atoi(mid));
                j = 0;
                ++i;
                while(arr[i] != '\0')
                    mid[j++] = arr[i++];
                mid[j] = '\0';
                y = func(atoi(mid));
                par[x] = y;
            }
            else
            {
                i = 2;
                j = 0;
                while(arr[i] != ' ')
                    mid[j++] = arr[i++];
                mid[j] = '\0';
                x = func(atoi(mid));
                j = 0;
                ++i;
                while(arr[i] != '\0')
                    mid[j++] = arr[i++];
                mid[j] = '\0';
                y = func(atoi(mid));
                if(x == y)
                    ++yes;
                else
                    ++no;
            }
        }
        printf("%d,%d\n", yes, no);
        if(cnt != t)
            printf("\n");
    }
    return 0;
}
