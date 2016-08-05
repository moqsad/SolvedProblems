#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int par[1100], arr[30000];

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
    int n, m, i, j, a, b, c, x, y;
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
        for(i = 0; i < m; ++i)
        {
            x = func(conn[i].u);
            y = func(conn[i].v);
            if(x == y)
            {
                arr[j++] = conn[i].w;
            }
            else
            {
                par[x] = y;
            }
        }
        if(j > 0)
        {
//            sort(arr, arr + j);
            printf("%d", arr[0]);
            for(i = 1; i < j; ++i)
                printf(" %d", arr[i]);
            printf("\n");
        }
        else
        {
            printf("forest\n");
        }
    }
    return 0;
}
