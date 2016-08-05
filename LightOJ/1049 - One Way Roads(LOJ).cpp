#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int pos, neg;

vector <int> edge[105], cost[105], direct[105];

void dfs(int s, int par)
{
    int i, j, x;
    for(i = 0; i < 2; ++i)
        if(edge[s][i] != par && edge[s][i] != 1)
        {
            x =  direct[s].size();

            for(j = 0; j < x; ++j)
                if(direct[s][j] == edge[s][i])
                {
                    pos += cost[s][i];
                    break;
                }

            if(j == x)
                neg += cost[s][i];

            dfs(edge[s][i], s);
        }
}

int main()
{
    int t, cnt, i, x, n, a, b, c;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            edge[a].push_back(b);
            edge[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);

            direct[a].push_back(b);
        }

        neg = pos = 0;
        dfs(1, edge[1][0]);
//        printf("%d %d___________\n", pos, neg);
        x = edge[1][0];
        for(i = 0; i < direct[x].size(); ++i)
            if(direct[x][i] == 1)
            {
                pos += cost[1][0];
                break;
            }

        if(i == direct[x].size())
            neg += cost[1][0];

//        printf("%d %d___________\n", pos, neg);
        printf("Case %d: %d\n", cnt, min(pos, neg));

        for(i = 1; i <= n; ++i)
        {
            edge[i].clear();
            cost[i].clear();
            direct[i].clear();
        }
    }
    return 0;
}
