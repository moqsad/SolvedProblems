#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

struct data
{
    long long day, cost, index;
    double dc;
};

vector <data> v;

bool comp(data p, data q)
{
    return p.dc < q.dc;
}

int main()
{
    long long t, cnt, i, n;
    data info;

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);

        for(i = 1; i <= n; ++i)
        {
            scanf("%lld %lld", &info.day, &info.cost);
            info.index = i;
            info.dc = (double) info.day / (double) info.cost;
            v.push_back(info);
        }

        sort(v.begin(), v.end(), comp);

        for(i = 0; i < n; ++i)
        {
            if(i == 0)
                printf("%lld", v[i].index);
            else
                printf(" %lld", v[i].index);
        }
        printf("\n");
        if(cnt < t)
            printf("\n");

        v.clear();
    }
    return 0;
}
