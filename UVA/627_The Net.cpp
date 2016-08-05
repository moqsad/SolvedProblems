#include "bits/stdc++.h"
using namespace std;

vector <int> v[360];
char arr[500], num[5];
int start, finish, dist[310], visit[310], collect[310];
queue <int> Q;
map <int, int> mm;

void BFS(void)
{
    memset(dist, -1, sizeof(dist));
    memset(visit, 0, sizeof(visit));

    while(!Q.empty())
        Q.pop();
    visit[start] = 1;
    dist[start] = 0;
    Q.push(start);

    int i, x, u, p = 0;

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = v[u].size();
        for(i = 0; i < x; ++i)
        {
            if(visit[v[u][i]] == 0)
            {
                Q.push(v[u][i]);
                visit[v[u][i]] = 1;
                dist[v[u][i]] = dist[u] + 1;
                mm[v[u][i]] = u;
            }
            if(v[u][i] == finish)
            {
                p = 1;
                break;
            }
        }
        if(p == 1)
            break;
    }
    return ;
}

int main()
{
    int cnt, i, j, n, q, x;
    while(scanf("%d", &n) == 1)
    {
        for(cnt = 1; cnt <= n; ++cnt)
        {
            scanf("%s", arr);
            i = 1;
            while(arr[i] != '-')
                ++i;
            if(arr[i + 1] != '\0')
                while(arr[i] != '\0')
                {
                    ++i;
                    j = 0;
                    while(!(arr[i] == ',' || arr[i] == '\0'))
                    {
                        num[j++] = arr[i];
                        ++i;
                    }
                    num[j] = '\0';
                    v[cnt].push_back(atoi(num));
                }
        }
        scanf("%d", &q);
        printf("-----\n");
        for(cnt = 0; cnt < q; ++cnt)
        {
            scanf("%d %d", &start, &finish);
            BFS();
            if(dist[finish] > -1)
            {
                i = 0;
                x = finish;
                    collect[i++] = x;
                while(mm[x] != start)
                {
                    collect[i++] = mm[x];
                    x = mm[x];
                }
                collect[i] = mm[x];
                for(j = i; j > 0; --j)
                {
                    printf("%d ", collect[j]);
                }
                printf("%d\n", collect[j]);
            }
            else
                printf("connection impossible\n");
        }
        for(cnt = 1; cnt <= n; ++cnt)
                v[cnt].clear();
    }
    return 0;
}

/*
6
1-2,3,4
2-1,3
3-1,2,5,6
4-1,5
5-3,4,6
6-3,5
6
1 6
1 5
2 4
2 5
3 6
2 1
10
1-2
2-
3-4
4-8
5-1
6-2
7-3,9
8-10
9-5,6,7
10-8
3
9 10
5 9
9 2
*/
