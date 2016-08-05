#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

map <char, int> m;

char arr[10], ch, par[200];

int func(char r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

int main()
{
    int  cnt, t, total;
    char value, i, x, y;

    scanf("%d\n", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        m.clear();
        scanf("%c", &ch);
        getchar();
        for(i = 'A'; i <= ch; ++i)
        {
            par[i] = i;
        }
        while(gets(arr))
        {
            if(arr[0] == '\0')
                break;
            x = func(arr[0]);
            y = func(arr[1]);
            par[x] = y;
        }
        total = 0;
        for(i = 'A'; i <= ch; ++i)
        {
            x = func(i);
            if(m.find(x) == m.end())
            {
                ++total;
                m[x] = 1;
            }
        }
        printf("%d\n", total);
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
