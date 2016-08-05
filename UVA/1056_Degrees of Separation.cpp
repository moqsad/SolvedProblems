#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>
#include <queue>
using namespace std;

vector <int> v[60];
queue <int> Q;
bool visit[60];
int dist[60];

map <string, int> mm;
char arr[11000], letter[11000];

void bfs(int start)
{
    memset(visit, 0, sizeof(visit));
    memset(dist, -1, sizeof(dist));

    Q.push(start);
    dist[start] = 0;
    visit[start] = 1;
    int i, u, x, y;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = v[u].size();
        for(i = 0; i < x; ++i)
        {
            y = v[u][i];
            if(visit[y] == 0)
            {
                visit[y] = 1;
                dist[y] = dist[u] +1;
                Q.push(y);
            }
        }
    }
}

int main()
{
    int n, m, i, j, total, p, k = 0;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(m == 0 && n == 0)
            break;
        j = 0;
        for(i = 0; i < m; ++i)
        {
            scanf("%s %s", arr, letter);
            if(mm.find(arr) == mm.end())
                mm[arr] = j++;
            if(mm.find(letter) == mm.end())
                mm[letter] = j++;
            v[mm[arr]].push_back(mm[letter]);
            v[mm[letter]].push_back(mm[arr]);
        }
        total = 0;
        p = 1;
        for(i =0; i < n; ++i)
        {
            bfs(i);
            for(j = 0; j < n; ++j)
            {
                if(dist[j] >= 0)
                {
                    if(dist[j] >  total)
                        total = dist[j];
                }
                else
                {
                    p = 0;
                    break;
                }
            }
            if(p == 0)
                break;
        }
        if(p == 1)
            printf("Network %d: %d\n\n", ++k, total);
        else
            printf("Network %d: DISCONNECTED\n\n", ++k);
        for(i = 0; i < n; ++i)
            v[i].clear();
        mm.clear();
    }
    return 0;
}
