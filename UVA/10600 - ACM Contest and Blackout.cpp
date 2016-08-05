#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int par[120], arr[120];

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
    int cnt, i, j, k, l, t, a, b, c, v, e, sum, total, x, y;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &v, &e);
        conn.clear();
        for(i = 1; i <= v; ++i)
            par[i] = i;
        for(i = 0; i < e; ++i)
        {
            scanf("%d %d %d", &a, &b, &c);
            info.u = a;
            info.v = b;
            info.w = c;
            conn.push_back(info);
        }
        sort(conn.begin(), conn.end(), comp);
        j = 0;
        sum = 0;
        c = v - 1;
        for(i = 0; i < e; ++i)
        {
            a = func(conn[i].u);
            b = func(conn[i].v);
            if(a != b)
            {
                par[a] = b;
                sum += conn[i].w;
                arr[j++] = i;
                if(j == c)
                    break;
            }
        }
        printf("%d", sum);

        y = 1000000000;
        for(i = 0; i < j; ++i)
        {
            for(l = 1; l <= v; ++l)
                par[l] = l;
            x = 0;
            total = 0;
            for(k = 0; k < e; ++k)
            {
                if(k != arr[i])
                {
                    a = func(conn[k].u);
                    b = func(conn[k].v);
                    if(a != b)
                    {
                        //printf("%d %d\n", conn[k].u, conn[k].v);
                        par[a] = b;
                        total += conn[k].w;
                        ++x;
                        if(x == c)
                            break;
                    }
                }
            }
            //printf("___________________\n");
            if(x == c && total < y)
                y = total;
        }
        printf(" %d\n",y);
    }
    return 0;
}
