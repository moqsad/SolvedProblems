#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

map <string, int> mm;
queue <int> Q;
vector <int> v[35];
bool visit[35][35], pass[35];
int start, finish, dist[35][35];
char arr[10], a[10], b[10];

void bfs(void)
{
    Q.push(start);
    dist[start][start] = 0;
    visit[start][start] = 1;

    int i, u, x, y;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = v[u].size();
        for(i = 0; i < x; ++i)
        {
            y = v[u][i];
            if(!visit[start][y])
            {
                dist[start][y] = dist[start][u] + 1;
                Q.push(y);
                visit[start][y] = 1;
            }
        }
    }
    return ;
}

int main()
{
    int t, cnt, i, n, m, p, mun;
    printf("SHIPPING ROUTES OUTPUT\n\n");
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        mm.clear();
        scanf("%d %d %d", &n, &m, &p);
        memset(visit, 0, sizeof(visit));
        memset(dist, -1, sizeof(dist));
        memset(pass, 0, sizeof(pass));
        for(i = 0; i < n; ++i)
        {
            scanf("%s", arr);
            mm[arr] = i;
        }
        for(i = 0; i < m; ++i)
        {
            scanf("%s %s", a, b);
            v[mm[a]].push_back(mm[b]);
            v[mm[b]].push_back(mm[a]);
        }
        printf("DATA SET  %d\n\n", cnt);
        for(i = 0; i < p; ++i)
        {
            scanf("%d %s %s", &mun, a, b);
            start = mm[a];
            finish = mm[b];
            if(!pass[start])
            {
                pass[start] = 1;
                bfs();
                if(dist[start][finish] >= 0)
                    printf("$%d\n", dist[start][finish] * mun * 100);
                else
                    printf("NO SHIPMENT POSSIBLE\n");
            }
            else
            {
                if(dist[start][finish] >= 0)
                    printf("$%d\n", dist[start][finish] * mun * 100);
                else
                    printf("NO SHIPMENT POSSIBLE\n");
            }
        }
        printf("\n");
        for(i = 0; i < n; ++i)
            v[i].clear();
    }
    printf("END OF OUTPUT\n");
    return 0;
}

/*
2
6  7  5
AA CC QR FF DD AB
AA CC
CC QR
DD CC
AA DD
AA AB
DD QR
AB DD
5  AA AB
14 DD CC
1  CC DD
2  AA FF
13 AB QR
3 0 1
AA BB CC
5  AA CC
*/
