#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

map <string, int> mm;

char arr[20][20], letter[20];
int num[20];

int main()
{
    int cnt = 0, i, n, j, x, money;
    while(scanf("%d", &n) == 1)
    {
        mm.clear();
        ++cnt;
        if(cnt > 1)
            printf("\n");
        for(i = 0; i < n; ++i)
        {
            scanf("%s", arr[i]);
            mm[arr[i]] = i;
        }
        memset(num, 0, sizeof(num));
        for(i = 0; i < n; ++i)
        {
            scanf("%s %d %d", letter, &money, &x);
            if(x > 0)
            num[mm[letter]] -= (money - money % x);
            for(j = 0; j < x; ++j)
            {
                scanf("%s", letter);
                num[mm[letter]] += money / x;
            }
        }
        for(i = 0; i < n; ++i)
        {
            printf("%s %d\n", arr[i], num[i]);
        }
    }
    return 0;
}
