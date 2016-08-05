#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

map <char, int> mm;
map <int, char> nn;

vector <int> edge[30];
int visit[30], p;
double value[30];

void bfs(int start)
{
    memset(visit, -1, sizeof(visit));
    queue <int> q;
    visit[start] = 0;
    q.push(start);
    int x, y, i, u, z;
    p = -1;
    while(!q.empty())
    {
        u = q.front();
        if(u == 0)
        {
            p = 0;
            return ;
        }
        q.pop();
        x = edge[u].size();
        for(i = 0; i < x; ++i)
        {
            y = edge[u][i];
            if(visit[y] == -1)
            {
                visit[y] = visit[u] + 1;
                q.push(y);
            }
        }
    }
    return ;
}


int main()
{
    int k = 0, i, j, n, x;
    char arr[40], ch;
    double ans, temp;
    while(scanf("%d", &n) == 1)
    {
        k = 0;

        for(j = 1; j <= n; ++j)
        {
            scanf(" %c", &ch);

            if(mm.find(ch) == mm.end())
            {
                mm[ch] = ++k;
                nn[k] = ch;
            }

            scanf("%lf %s", &value[mm[ch]], arr);

            x = strlen(arr);
            for(i = 0; i < x; ++i)
            {
                if(arr[i] >= 'A' && arr[i] <= 'Z')
                {
                    if(mm.find(arr[i]) == mm.end())
                    {
                        mm[arr[i]] = ++k;
                        nn[k] = arr[i];
                    }
                    edge[mm[ch]].push_back(mm[arr[i]]);
                }
                else
                    edge[mm[ch]].push_back(0);
            }
        }


        ans = 0;
        ch = 'a';
        for(i = 1; i <= n; ++i)
        {
            bfs(i);
            if(p == 0)
            {
                temp = value[i];
                for(j = 1; j < visit[0]; ++j)
                    temp -= .05 * temp;

                if(temp > ans)
                {
                    ans = temp;
                    ch = nn[i];
                }

                else if(ans == temp && nn[i] < ch)
                    ch = nn[i];
            }
        }

        printf("Import from %c\n", ch);

        for(i = 1; i <= n; ++i)
            edge[i].clear();
        mm.clear();
        nn.clear();
    }
    return 0;
}
