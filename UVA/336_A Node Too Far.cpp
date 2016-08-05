#include "bits/stdc++.h"
using namespace std;

map <int, int> mm;
void bfs(int a, int b);

int i, visit[35], dist[35], arr[35][35];
queue <int> Q;

int main()
{
//    freopen("1.txt","r",stdin);
//    freopen("4.txt","w",stdout);
    int n, cnt, j = 0, k, a, b, sum;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        memset(arr, 0, sizeof(arr));
        i = 0;
        mm.clear();
        for(cnt = 0; cnt < n; ++cnt)
        {
            scanf("%d %d", &a, &b);
            if(mm.find(a) == mm.end())
                mm[a] = ++i;
            if(mm.find(b) == mm.end())
                mm[b] = ++i;
            arr[mm[a]][mm[b]] = 1;
            arr[mm[b]][mm[a]] = 1;
        }
        while(scanf("%d %d", &a, &b) == 2)
        {
            if(a == 0 && b == 0)
                break;
            sum = 0;
            ++j;

            bfs(a, b);
            for(k = 1; k <= i; ++k)
                if(dist[k] > b || dist[k] == -1)
                    ++sum;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", j, sum, a, b);
        }
    }
    return 0;
}

void bfs(int a, int b)
{
    memset(visit, 0, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    while(!Q.empty())
        Q.pop();
    visit[mm[a]] = 1;
    dist[mm[a]] = 0;
    Q.push(mm[a]);

    int j, u, p;
    p = 0;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(j=1; j<=i; j++)
        {
            if(arr[u][j] == 1 && visit[j] == 0)
            {
                dist[j] = dist[u] + 1;
//                if(dist[j] > b)
//                {
//                    p = 1;
//                    break;
//                }
                visit[j] = 1;
                Q.push(j);
            }
        }
//        if(p == 1)
//            break;
    }
    return ;
}
/*14
1 2 2 7 1 3 3 4 3 5 5 10 5 11 4 6  7 6 7 8 7 9 8 9 8 6 6 11*/
