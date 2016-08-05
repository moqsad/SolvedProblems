#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

set <int> mm;

int main()
{
    int m, n, i, a, ans;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(!n && !m)
            break;
        ans = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            mm.insert(a);
        }
        for(i = 0; i < m; ++i)
        {
            scanf("%d", &a);
            if(mm.find(a) != mm.end())
                ++ans;
        }
        printf("%d\n", ans);
        mm.clear();
    }
    return 0;
}
