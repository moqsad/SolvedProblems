#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;

char a[40], b[40];
int par[300], arr[300][300], value[300][300], start, finish, total, n, det;

void dfs(int x)
{
    int i;
    for(i = 1; i <= n; ++i)
    {
        if(arr[x][i] == 1)
        {
            arr[x][i] = 0;
            arr[i][x] = 0;

            if(i == finish)
            {
                det = 1;
                if(value[x][i] < total)
                    total = value[x][i];
                return;
            }
            dfs(i);
            if(det == 1)
            {
                if(value[x][i] < total)
                    total = value[x][i];
                return;
            }
        }
    }
    return;
}

struct data
{
    int u, v, w;
};

bool comp(data p, data q)
{
    return p.w > q.w;
}

vector <data> road;
map <string, int> m;

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

int main()
{
    int r, i, j, cnt, c, x, y, cas = 0;
    data info;
    while(scanf("%d %d", &n, &r) == 2)
    {
        if(n == 0 && r == 0)
            break;
        memset(arr, 0, sizeof(arr));
        m.clear();
        road.clear();
        total = 200000;
        det = 0;
        for(i = 1; i <= n; ++i)
        {
            par[i] = i;
        }
        j = 0;
        for(i = 0; i < r; ++i)
        {
            scanf("%s %s", a, b);
            if(m.find(a) == m.end())
            {
                m[a] = ++j;
            }
            if(m.find(b) == m.end())
            {
                m[b] = ++j;
            }
            scanf("%d", &c);
            info.u = m[a];
            info.v = m[b];
            info.w = c;
            road.push_back(info);
        }
        sort(road.begin(), road.end(), comp);
        x = road.size();
        int p, q, g, h;
        cnt = 0;
        y = n - 1;
        for(i = 0; i < x; ++i)
        {
            g = road[i].u;
            h = road[i].v;
            p = func(g);
            q = func(h);
            if(p != q)
            {
                arr[g][h] = 1;
                arr[h][g] = 1;
                value[g][h] = road[i].w;
                value[h][g] = road[i].w;
                par[p] = q;
                ++cnt;
                if(cnt == y)
                    break;
            }
        }
        scanf("%s %s", a, b);
        start = m[a];
        finish = m[b];
        dfs(start);
        printf("Scenario #%d\n", ++cas);
        printf("%d tons\n\n", total);
    }
    return 0;
}
