#include <bits/stdc++.h>
using namespace std;

#define sz 105

string line;
vector <int> edge[sz];
int ans, low[sz], dist[sz], time_;

void arti(int node, int par)
{
    int i, x = edge[node].size(), y, p = 0, child = 0;

    dist[node] = low[node] = ++time_;

    for(i = 0; i < x; ++i)
    {
        y = edge[node][i];
        if(!dist[y])
        {
            arti(y, node);
            low[node] = min(low[node], low[y]);

            if((par == -1 && ++child == 2) || (par != -1 && dist[node] <= low[y]))
                p = 1;
        }
        else if(y != par)
            low[node] = min(low[node],dist[y]); // low[y] dile ai code e WA khai........., niche test case dea ace
    }
    if(p == 1)
        ++ans;
}

int main()
{
    int n, x, y, i;
    while(scanf("%d", &n) == 1 && n)
    {
        scanf("\n");
        time_ = ans = 0;
        while(getline(cin, line))
        {
            stringstream sin (line);
            sin >> x;
            if(x)
            {
                while(sin >> y)
                {
                    edge[x].push_back(y);
                    edge[y].push_back(x);
                }
            }
            else
                break ;
        }

        memset(dist, 0, sizeof(dist));
        for(i = 1; i <= n; ++i)
        {
            if(!dist[i])
                arti(i, -1);
            edge[i].clear();
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
5
1 2 3
2 3 4
4 5
5 2
0
*/
