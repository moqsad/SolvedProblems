#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector <int> v[210];
int colour[210], p, total1, total2;
queue <int> Q;

void bfs(int start)
{
    colour[start] = 1;
    Q.push(start);
    int x, y, e, u, i;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        x = colour[u];
        if(x == 1)
            y = 2;
        else
            y = 1;
        e = v[u].size();
        for(i = 0; i < e; ++i)
        {
            if(!colour[v[u][i]])
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
                    p = 0;
            }
        }
    }
    return;
}

int main()
{
    int i, j, n, m, t, cnt, x, sum;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        scanf("%d", &n);
        sum = 0;
        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &m);
            for(j = 0; j < m; ++j)
            {
                scanf("%d", &x);
                if(x <= n)
                {
                    v[i].push_back(x);
                    v[x].push_back(i);
                }
            }
        }
        p = 1;
        total1 = 1;
        total2 = 0;
        for(i = 1; i <= n; ++i)
        {
            if(!colour[i])
            {
                bfs(i);
                if(p == 1)
                    sum += total1 > total2 ? total1 : total2;
                p = 1;
                total1 = 1;
                total2 = 0;
            }
        }
        printf("%d\n", sum);
        for(i = 1; i <= n; ++i)
        {
            v[i].clear();
            colour[i] = 0;
        }
    }
    return 0;
}
/*
1

4
2 2 3
3 1 3 4
2 1 2
1 2
*/
/*
1

5
5 2 4 6 8 10
3 1 3 6
0
0
3 1 6 7
*/
