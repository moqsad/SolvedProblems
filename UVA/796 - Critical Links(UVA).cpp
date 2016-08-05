#include <bits/stdc++.h>
using namespace std;

#define sz 100010

struct data
{
    int u, v;
}arr[1000010];

vector <int> edge[sz];
int dist[sz], low[sz], total, ans;

bool comp(data p, data q)
{
    if(p.u != q.u)
        return p.u < q.u;
    return p.v < q.v;
}

// jodio ai problem tate shudu first element er vittite sort korte bola hoice, kintu accepted paowar
// jonno -> jodi first element soman hoi, tahole second eelement er vittite sort korte hobe.......

void arti(int node, int par)
{
    int i, x = edge[node].size(), y;

    low[node] = dist[node] = ++total;

    for(i = 0; i < x; ++i)
    {
        y = edge[node][i];

        if(!dist[y])
        {
            arti(y, node);

            low[node] = min(low[node], low[y]);

            if(dist[node] < low[y])
            {
                arr[ans].u = min(node, y);
                arr[ans++].v = max(node, y);
            }
        }

        else if(y != par)
        low[node] = min(low[node], dist[y]);
    }
}

int main()
{
    int n, i, j, a, b, x;
    while(scanf("%d", &n) == 1)
    {
        total = ans = 0;

        for(i = 0; i < n; ++i)
        {
            scanf("%d (%d)", &a, &x);
            for(j = 0; j < x; ++j)
            {
                scanf("%d", &b);
                edge[a].push_back(b);
                edge[b].push_back(a);
            }
        }

        for(i = 0; i < n; ++i)
        {
            if(!dist[i])
                arti(i, -1);
        }

        sort(arr, arr + ans, comp);
        printf("%d critical links\n", ans);
        for(i = 0; i < ans; ++i)
            printf("%d - %d\n", arr[i].u, arr[i].v);
        printf("\n");

        for(i = 0; i < n; ++i)
        {
            edge[i].clear();
            dist[i] = 0;
        }
    }
    return 0;
}
