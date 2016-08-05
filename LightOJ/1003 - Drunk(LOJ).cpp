#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

map <string, int> mm;
vector <int> edge[10010];

int cycle, visited[10010];
char a[15], b[15];

void visit(int x)
{
    if(visited[x] == 2 || cycle)
        return ;

    if(visited[x] == 1)
    {
        cycle = 1;
        return ;
    }

    int i, y;
    y = edge[x].size();
    visited[x] = 1;
    for(i = 0; i < y; ++i)
        visit(edge[x][i]);
    visited[x] = 2;
}

int main()
{
    int i, j, cnt, t, n;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        j = 0;
        for(i = 0; i < n; ++i)
        {
            scanf("%s %s", a, b);

            if(mm.find(a) == mm.end())
                mm[a] = j++;

            if(mm.find(b) == mm.end())
                mm[b] = j++;

            edge[mm[b]].push_back(mm[a]);
        }

        memset(visited, 0, sizeof(visited));
        cycle = 0;
        for(i = 0; i < j; ++i)
        {
            if(visited[i] == 0)
            {
                visit(i);
                if(cycle == 1)
                    break;
            }
        }

        if(cycle == 0)
            printf("Case %d: Yes\n", cnt);
        else
            printf("Case %d: No\n", cnt);
        mm.clear();
        for(i = 0; i < j; ++i)
            edge[i].clear();
    }
    return 0;
}
