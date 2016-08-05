#include <cstdio>
#include <cstring>
using namespace std;

int dist[110][110], arr[110];

int small(int a, int b)
{
    return (a < b) ? a : b;
}

void floyd(int n)
{
    int i, j, k;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
            for(k = 1; k <= n; ++k)
            {
                dist[j][k] = small(dist[j][k], dist[j][i] + dist[i][k]);
//                printf("%d %d %d --> %d -->  %d --> %d\n", i, j, k, dist[j][k], dist[j][i], dist[i][k]);
            }
}

int main()
{
    int n, m, i, j, k, a, b, ans;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;

        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
                dist[i][j] = 999999999;

        while(scanf("%d", &a) == 1)
        {
            if(a == 0)
                break;
            while(scanf("%d", &b) == 1)
            {
                if(b == 0)
                    break;
                dist[a][b] = 1;
            }
        }
        floyd(n);

        scanf("%d", &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%d", &a);
            ans = 0;
            k = 0;
            for(j = 1; j <= n; ++j)
                if(dist[a][j] == 999999999)
                {
                    arr[++k] = j;
                    ++ans;
                }
            printf("%d", ans);
            for(j = 1; j <= k; ++j)
                printf(" %d", arr[j]);
            printf("\n");
        }
    }
    return 0;
}

/*
3
1 2 0
2 1 0
0
3 1 2 3
0
*/
