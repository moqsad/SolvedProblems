#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int colour[210], p, total1, total2;

vector <int> v[210];

void bfs(int start)
{
    queue <int> Q;
    colour[start] = 1;
    Q.push(start);
    int x, y, i, u, j;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = colour[u];
        if(x == 1)
            y = 2;
        else
            y = 1;
        for(i = 0; i < v[u].size(); ++i)
        {
            if(colour[v[u][i]] == 0)
            {
                colour[v[u][i]] = y;
                if(y == 1)
                    ++total1;
                else
                    ++total2;
                Q.push(v[u][i]);
            }
            else
            {
                if(colour[v[u][i]] == x)
                {
                    p = 0;
                    break;
                }
            }
        }
        if(p == 0)
            break;
    }
    return ;
}

int main()
{
    int n, m, a, b, i, j, sum, cnt, t;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        p = 1;
        sum = 0;
        total1 = 1;
        for(i = 0; i < n; ++i)
        {
            if(colour[i] == 0)
            {
                bfs(i);
                if(total2 == 0)
                    total2 = 1;
                sum += total1 < total2 ? total1 : total2;
                if(p == 0)
                    break;
                total1 = 1;
                total2 = 0;
            }
        }
        if(p == 1)
            printf("%d\n", sum);
        else
            printf("-1\n");
        for(i = 0; i < n; ++i)
        {
            v[i].clear();
            memset(colour, 0, sizeof(colour));
        }
    }
    return 0;
}

