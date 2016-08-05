#include <map>
#include <cstring>
#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

map <string, int> mm;
string a;
queue <int> Q;
vector <int> v[5500];
char arr[11000], name[500];
int dist[5500], finish;
bool visit[5500];


void BFS(void)
{
    memset(visit, 0, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    while(!Q.empty())
        Q.pop();

    Q.push(1);
    visit[1] = 1;
    dist[1] = 0;

    int u, x, i, p = 0;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = v[u].size();
        for(i = 0; i < x; ++i)
        {
            if(visit[v[u][i]] == 0)
            {
                dist[v[u][i]] = dist[u] + 1;
                visit[v[u][i]] = 1;
                Q.push(v[u][i]);
             }
        }
    }
    return ;
}

int main()
{
    int t, p, n, cnt, i, j, k, l, m, x, det, num[50];
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &p, &n);
        getchar();
        mm["Erdos, P."] = 1;
        m = 1;
        for(i = 0; i < p; ++i)
        {
            gets(arr);
            k = 0;
            l = 0;
            j = 0;
            det = 0;
           while(1)
            {
                name[l] = arr[k];
                if(arr[k] == ',')
                    ++det;
                if(det == 2 || arr[k] == ':')
                {
                    name[l] = '\0';
                    if(mm.find(name) == mm.end())
                    {
                        a = name;
                        mm[name] = ++m;
                    }
                    num[j++] = mm[name];
                    det = 0;
                    l = -1;
                    if(arr[k] == ':')
                        break;
                    ++k;
                }
                ++k;
                ++l;
            }
            x = j - 1;
            for(k = 0; k < x; ++k)
            {
                for(l = k + 1; l < j; ++l)
                {
                    v[num[k]].push_back(num[l]);
                    v[num[l]].push_back(num[k]);
                }
            }
        }
        printf("Scenario %d\n", cnt);
        BFS();
        for(i = 0; i < n; ++i)
        {
            gets(name);
            if(mm.find(name) != mm.end())
            {
                finish = mm[name];
                if(dist[finish] > -1)
                    printf("%s %d\n", name, dist[finish]);
                else
                    printf("%s infinity\n", name);
            }
            else
                printf("%s infinity\n", name);
        }
        mm.clear();
        for(i = 1; i <= m; ++i)
        v[i].clear();
    }
    return 0;
}
