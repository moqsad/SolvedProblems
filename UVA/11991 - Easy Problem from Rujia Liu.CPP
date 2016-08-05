#include <cstdio>
#include <map>
#include <iostream>
using namespace std;

struct data
{
    int x, y;
};

map <int, int> nn;
map <data, int> mm;

int main()
{
    int n, m, i, a;
    data info;
    while(scanf("%d %d", &n, &m) == 2)
    {
        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &a);
            if(nn.find(a) == nn.end())
            {
                nn[a] = 1;
                info.x = a;
                info.y = 1;
//                mm[info] = i;
            }
            else
            {
                ++nn[a];
                info.x = a;
                info.y = nn[a];
//                mm[info] = i;
            }
        }

//        for(i = 0; i < m; ++i)
//        {
//            scanf("%d %d", &info.x, &info.y);
//            if(mm.find(info) != mm.end())
//                printf("%d\n", mm[info]);
//            else
//                printf("0\n");
//        }
        mm.clear();
        nn.clear();
    }
    return 0;
}
