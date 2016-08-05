#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

vector <int> edge[1005];
int visit[1005], arr[1005], sum, num;

void dfs(int s)
{
    visit[s] = 1;
    num += 1;
    sum += arr[s];

    int i, x = edge[s].size();

    for(i = 0; i < x; ++i)
        if(!visit[edge[s][i]])
            dfs(edge[s][i]);
}

int main()
{
    int t, cnt, i, a, b, n, m, p, avg;

    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &m);

        for(i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);

        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }

        p = 1;
        num = 0, sum = 0;
        dfs(1);

        if(sum % num > 0)
            p = 0;

        else
        {
            avg = sum / num;
            for(i = 2; i <= n; ++i)
            {
                if(!visit[i])
                {
                    sum = num = 0;
                    dfs(i);
                    if(sum % num > 0 || sum / num != avg)
                    {
                        p = 0;
                        break;
                    }
                }
            }
        }

        if(p == 1)
            printf("Case %d: Yes\n", cnt);
        else
            printf("Case %d: No\n", cnt);

        for(i = 1; i <= n; ++i)
        {
            edge[i].clear();
            visit[i] = 0;
        }
    }
    return 0;
}
