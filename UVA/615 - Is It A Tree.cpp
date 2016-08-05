#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

vector <int> edge[50000], graph[50000];
map <int, int> mm;
int dist[50000];
queue <int> Q;

void bfs(int start)
{
    memset(dist, 0, sizeof(dist));

    dist[start] = 2;
    Q.push(start);
    int u, i, x, y;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = graph[u].size();
        for(i = 0; i < x; ++i)
        {
            y = graph[u][i];
            dist[y] = 2;
            Q.push(y);
        }
    }
}

int main()
{
    int cnt = 0, a, b, i = 0, j, p = 1, q = 1, r, start;
    while(scanf("%d %d", &a, &b) == 2)
    {
        if(a == -1 && b == -1)
            break;

        if(a == 0 && b == 0)
        {
            if(p == 0)
                printf("Case %d is not a tree.\n", ++cnt);
            else if(i == 0)
                printf("Case %d is a tree.\n", ++cnt);

            else
            {
                r = 0;
                for(j = 0; j < i; ++j)
                {
                    if(edge[j].size() == 0)
                    {
                        bfs(j);
                        r = 1;
                        break;
                    }
                }

                if(r == 0)
                    printf("Case %d is not a tree.\n", ++cnt);

                else
                {
                    for(j = 0; j < i; ++j)
                        if(dist[j] < 2)
                        {
                            q = 0;
                            printf("Case %d is not a tree.\n", ++cnt);
                            break;
                        }

                    if(q == 1)
                        printf("Case %d is a tree.\n", ++cnt);
                }
            }
            for(j = 0; j < i; ++j)
            {
                edge[j].clear();
                graph[j].clear();
            }
            mm.clear();
            p = 1;
            q = 1;
            i = 0;
        }

        if(p == 1 && a != 0 && b != 0)
        {
            if(mm.find(a) == mm.end())
                mm[a] = i++;
            if(mm.find(b) == mm.end())
                mm[b] = i++;
            graph[mm[a]].push_back(mm[b]);
            edge[mm[b]].push_back(mm[a]);
            if(edge[mm[b]].size() == 2)
                p = 0;
        }
    }
    return 0;
}

/*
1 2
2 3
4 5
5 6
6 4
0 0

1 2
2 3
4 5
5 6
0 0
*/
