#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int par[1100000];

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

struct data
{
    int u, v, w;
};

vector <data> conn;

bool comp(data p, data q)
{
    return p.w < q.w;
}

int main()
{
    int n, m, i, j, a, b, c, x, y, total;
    data info;
    while(scanf("%d %d", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
            break;
        conn.clear();
        for(i = 0; i < n; ++i)
            par[i] = i;
        for(i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            info.u = a;
            info.v = b;
            info.w = c;
            conn.push_back(info);
        }
        sort(conn.begin(), conn.end(), comp);
        j = 0;
        total = 0;
        c = n - 1;
        for(i = 0; i < m; ++i)
        {
            x = func(conn[i].u);
            y = func(conn[i].v);
            if(x != y)
            {
                par[x] = y;
                if(total < conn[i].w)
                    total = conn[i].w;
                ++j;
                if(j == c)
                    break;
            }
        }
        if(j == c && j != 0)   //1 0 inputer jonno ans--> IMPOSSIBLE.
            printf("%d\n", total);
        else
            printf("IMPOSSIBLE\n");

    }
    return 0;
}

