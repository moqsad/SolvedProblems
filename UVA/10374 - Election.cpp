#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

map <string, int> mm;

char letter[25][90], arr[25][90], ans[90];
int num[25];

int main()
{
    int t, cnt, i, n, m, total, index, p;

    scanf("%d\n", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        mm.clear();
        scanf("%d\n", &n);
        for(i = 0; i < n; ++i)
        {
            gets(arr[i]);
            gets(letter[i]);
            num[i] = 0;
            mm[arr[i]] = i;
        }
        scanf("%d\n", &m);
        for(i = 0; i < m; ++i)
        {
            gets(ans);
            if(mm.find(ans) != mm.end())
                ++num[mm[ans]];
        }
        total = 0;
        p = 1;
        for(i = 0; i < n; ++i)
            if(num[i] > total)
            {
                index = i;
                total = num[i];
                p = 1;
            }
            else if(total == num[i])
                ++p;
        if(p < 2)
            printf("%s\n", letter[index]);
        else
            printf("tie\n");
        if(cnt < t)
            printf("\n");
    }
    return 0;
}
