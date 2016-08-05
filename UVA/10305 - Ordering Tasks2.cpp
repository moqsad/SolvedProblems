#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector <int> v[110];
int value[110], ans[110];

queue <int> q;

int main()
{
    int n, m, i, j, x, u, a, b;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
            break;
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            ++value[b];
        }

        for(i = 1; i <= n; ++i)
            if(value[i] == 0)
                q.push(i);

        j = 0;
        while(!q.empty())
        {
            u = q.front();
            q.pop();
            ans[j++] = u;
            x = v[u].size();
//        printf("____________\n");
            for(i = 0; i < x; ++i)
            {
                --value[v[u][i]];
                if(value[v[u][i]] == 0)
                    q.push(v[u][i]);
            }
        }
        printf("%d", ans[0]);
        for(i = 1; i < j; ++i)
        {
            printf(" %d", ans[i]);
            value[i] = 0;
            v[i].clear();
        }
        value[i] = 0;
        v[i].clear();
        printf("\n");
    }
    return 0;
}
