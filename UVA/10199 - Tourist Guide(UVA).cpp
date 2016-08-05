#include <bits/stdc++.h>
using namespace std;

#define sz 105

map <string, int> mm;
map <int, string> nn;
string s[sz];
int dist[sz], low[sz], ans, total;
char arr[40], a[40], b[40];
vector <int> edge[sz];

void arti(int node, int par)
{
    int i, x = edge[node].size(), y, p = 0, child = 0;

    low[node] = dist[node] = ++total;

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
        low[node] = min(low[node], dist[y]);
    }

    if(p == 1)
        s[ans++] = nn[node];
}

int main()
{
    int n, m, i, cnt = 0;
    while(scanf("%d", &n) == 1 && n)
    {
        for(i = 0; i < n; ++i)
        {
            scanf("%s", arr);
            mm[arr] = i;
            nn[i] = arr;
        }

        scanf("%d", &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%s %s", a, b);
            edge[mm[a]].push_back(mm[b]);
            edge[mm[b]].push_back(mm[a]);
        }

        ans = total = 0;
        for(i = 0; i < n; ++i)
        {
            if(!dist[i])
                arti(i, -1);
        }

        for(i = 0; i < n; ++i)
        {
            edge[i].clear();
            dist[i] = 0;
        }

        sort(s, s + ans);

        if(cnt++ > 0)
            printf("\n");
        printf("City map #%d: %d camera(s) found\n", cnt, ans);
        for(i = 0; i < ans; ++i)
        cout << s[i] << "\n";

        mm.clear();
        nn.clear();
    }
    return 0;
}
