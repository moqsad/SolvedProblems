#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int n, j, par[100002][20], cost[100002];

void lca_init(void)
{
    int i;

    for (j = 1; (1 << j) < n; j++)
        for (i = 0; i < n; i++)
        {
            if(par[i][j - 1] != -1)
                par[i][j] = par[par[i][j - 1]][j - 1];
        }
}

int main()
{
    int t, cnt, q, i, k, l, v;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &q);

        memset(par, -1, sizeof(par));

        cost[0] = 1;

        for(i = 1; i < n; ++i)
            scanf("%d %d", &par[i][0], &cost[i]);

        lca_init();

        printf("Case %d:\n", cnt);
        for(i = 0; i < q; ++i)
        {
            scanf("%d %d", &k, &v);

            for(l = j - 1; l >= 0; --l)
                if(par[k][l] != -1 && cost[par[k][l]] >= v)
                    k = par[k][l];

            printf("%d\n", k);
        }
    }
    return 0;
}
