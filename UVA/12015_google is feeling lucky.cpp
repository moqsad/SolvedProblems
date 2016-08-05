#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

vector <int> v[110];

int main()
{
    char arr[10][110];
    int cnt, i, n, x, y, t;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        x = 0;
        for(i = 0; i < 10; ++i)
        {
            scanf("%s %d", arr[i], &n);
            if(n > x)
                x = n;
            v[n].push_back(i);
        }
        y = v[x].size();
        printf("Case #%d:\n", cnt);
        for(i = 0; i < y; ++i)
            printf("%s\n", arr[v[x][i]]);
        for(i = 0; i < 100; ++i)
            v[i].clear();
    }
    return 0;
}
