#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int arr[1250000][4][2], x, sz, max_;
char a[60];

map <char, int> mm;

void func(int pos, int index)
{
    int data = mm[a[index]];
    if(index == x)
    {
        if(arr[pos][data][0] == -1)
        {
            arr[pos][data][1] = 1;
            arr[pos][data][0] = ++sz;
            max_ = max(max_, index + 1);
        }

        else
        {
            ++arr[pos][data][1];
            max_ = max(arr[pos][data][1] * (index + 1), max_);
        }

        return ;
    }

    if(arr[pos][data][0] == -1)
    {
        arr[pos][data][1] = 1;
        arr[pos][data][0] = ++sz;
        func(sz, index + 1);
    }

    else
    {
        ++arr[pos][data][1];
        max_ = max(arr[pos][data][1] * (index + 1), max_);
        func(arr[pos][data][0], index + 1);
    }
}

int main()
{
    int t, cnt, n, i;
    mm['A'] = 0, mm['C'] = 1, mm['G'] = 2, mm['T'] = 3;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        sz = 0;
        max_ = 0;
        memset(arr, -1, sizeof(arr));
        scanf("%d", &n);
        for(i = 0; i < n; ++i)
        {
            scanf("%s", a);
            x = strlen(a) - 1;
            func(0, 0);
        }
        printf("Case %d: %d\n", cnt, max_);
    }

    return 0;
}
