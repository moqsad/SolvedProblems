#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int par[550];
char arr[550][6];

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

vector <data> road;

bool comp(data p, data q)
{
    return p.w < q.w;
}

int funct(int a, int b)
{
    int sum, x;
    sum = b - a;
    if(sum >= 0)
    {
        x = a + 10 - b;
        if(x < sum)
            sum = x;
    }
    else
    {
        sum = - sum;
        x = b + 10 - a;
        if(x < sum)
            sum = x;
    }
    return sum;
}

int main()
{
    int t, i, j, k, cnt, x, y, z, n, a, b, sum;
    data info;
    scanf("%d", &t);
    for(cnt = 0; cnt < t; ++cnt)
    {
        road.clear();
        strcpy(arr[0], "0000");
        sum = 1000000000;
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
        {
            par[i] = i;
            scanf("%s", arr[i]);
            x = 0;
            for(k = 0; k < 4; ++k)
            {
                a = arr[i][k];
                b = arr[0][k];
                x += funct(a, b);
            }
            if(sum > x)
                sum = x;
        }
        for(i = 1; i < n; ++i)
        {
            for(j = i + 1; j <= n; ++j)
            {
                info.u = i;
                info.v = j;
                x = 0;
                for(k = 0; k < 4; ++k)
                {
                    a = arr[i][k];
                    b = arr[j][k];
                    x += funct(a, b);
                }
                info.w = x;
                road.push_back(info);
            }
        }
        n = n - 1;
        sort(road.begin(), road.end(), comp);
        x = road.size();
        j = 0;
        for(i = 0; i < x; ++i)
        {
            y = func(road[i].u);
            z = func(road[i].v);
            if(y != z)
            {
                par[y] = z;
                sum += road[i].w;
                ++j;
                if(j == n)
                    break;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
