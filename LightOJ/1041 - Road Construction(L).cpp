#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int par[110];

map <string, int> mm;

struct data
{
    int u, v, w;
};

vector <data> v;

bool comp(data p, data q)
{
    return p.w < q.w;
}

int func(int r)
{
    if(par[r] == r)
        return r;
    else
        return par[r] = func(par[r]);
}

int main()
{
    int t, cnt, i, j, k, x, y, z, c, m, sum;
    char a[100], b[100];
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        j = 0;
        k = 1;
        scanf("%d", &m);
        for(i = 0; i < m; ++i)
        {
            scanf("%s %s %d", a, b, &c);
            if(mm.find(a) == mm.end())
            {
                mm[a] = ++j;
                par[j] = j;
            }

            if(mm.find(b) == mm.end())
            {
                mm[b] = ++j;
                par[j] = j;
            }

            if(c == 0)
            {
                x = func(mm[a]);
                y = func(mm[b]);
                if(x != y)
                    ++k;
                par[x] = y;
            }

            else
            {
                info.u = mm[a];
                info.v = mm[b];
                info.w = c;
                v.push_back(info);
            }
        }
//        printf("%d+++++++++++\n", j);
        sort(v.begin(), v.end(), comp);
        sum = 0;
        z = v.size();
        k = j - k;
        j = 0;
        for(i = 0; i < z; ++i)
        {
            x = func(v[i].u);
            y = func(v[i].v);
            if(x != y)
            {
                sum += v[i].w;
                par[x] = y;
                ++j;
                if(j == k)
                    break;
            }
        }

        if(j == k)
            printf("Case %d: %d\n", cnt, sum);
        else
            printf("Case %d: Impossible\n", cnt);
        v.clear();
        mm.clear();
    }
    return 0;
}
