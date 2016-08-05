#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map <int, int> mm;

int  visit[2010], num[130];

int main()
{
    int t, cnt, i, x, prime[500], j, k = 2, l, m, p;
    char arr[3000];

    prime[k] = 2;
    mm[2] = 1;
    for(j = 3; j <= 2001; j += 2)
    {
        if(visit[j] == 0)
        {
            prime[++k] = j;
            mm[j] = 1;
            l = j + j;
            for(m = j * j; m <= 2001; m += l)
            {
                visit[m] = 1;
            }
        }
    }

    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%s", arr);
        x = strlen(arr);
        memset(num, 0, sizeof(num));
        for(i = 0; i < x; ++i)
        {
            ++num[arr[i]];
        }
        printf("Case %d: ", cnt);
        p = 0;
        for(i = 48; i < 123; ++i)
        {
            if(mm.find(num[i]) != mm.end())
            {
                p = 1;
                printf("%c", i);
            }
        }
        if(p == 0)
            printf("empty");
        printf("\n");
    }
    return 0;
}
