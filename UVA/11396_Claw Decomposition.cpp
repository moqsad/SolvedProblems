#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int colour[310000], p;

vector <int> v[310000];
queue <int> Q;

void bfs(int start)
{
    while(!Q.empty())
        Q.pop();
    colour[start] = 1;
    Q.push(start);
    int x, y, i, u;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = colour[u];
        if(x == 1)
            y = 2;
        else
            y = 1;
        for(i = 0; i < 3; ++i)
        {
            if(colour[v[u][i]] == 0)
            {
                colour[v[u][i]] = y;
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
    int n, a, b, i, j;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;
        p = 1;
        memset(colour, 0, sizeof(colour));
        while(scanf("%d %d", &a, &b) == 2)
        {
            if(a == 0 || b == 0)
                break;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(i = 1; i <= n; ++i)
        {
            if(colour[i] == 0)
            {
                bfs(i);
                if(p == 0)
                    break;
            }
        }
        if(p == 1)
            printf("YES\n");
        else
            printf("NO\n");
        for(i = 1; i <= n; ++i)
            v[i].clear();
    }
    return 0;
}
