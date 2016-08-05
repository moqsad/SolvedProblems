#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int num[10];

vector <int> v[600];

int main()
{
    int cnt, t, n, m, a, b, p, i;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);

        memset(num, 0, sizeof(num));
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }

        p = 0;
        for(i = 1; i <= n; ++i)
        {
            if(v[i].size() > 4)
            {
                p = 1;
                break;
            }
            else
                ++num[v[i].size()];
        }
        if(p == 0)
        {
            if(num[4] == 1 && num[3] == 0 && num[1] == 4)
                printf("Case %d: X\n", cnt);
            else if(num[3] == 1 && num[4] == 0 && num[1] == 3)
                printf("Case %d: Y\n", cnt);
            else if(num[3] == 0 && num[4] == 0 && num[1] == 2)
                printf("Case %d: I\n", cnt);
            else
                printf("Case %d: NotValid\n", cnt);
        }
        else
            printf("Case %d: NotValid\n", cnt);
        for(i = 1; i <= n; ++i)
            v[i].clear();
    }
    return 0;
}
