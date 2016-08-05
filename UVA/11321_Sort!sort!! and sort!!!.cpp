#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct data
{
    long long int u;
    long long int v;
};

vector <data> v;

bool comp(data p, data q)
{
    if(p.v == q.v)
    {
        if((p.u % 2 == 1 || p.u % 2 == -1) && (q.u % 2 == 1 || q.u % 2 == -1))
        {
            return p.u > q.u;
        }
        else if(p.u % 2 == 0 && q.u % 2 == 0)
            return p.u < q.u;
        else
        {
            return(p.u % 2 == 1 || p.u % 2 == -1);
        }
    }
    else
        return p.v < q.v;
}

int main()
{
    long long int n, m, i, a;
    data info;
    while(scanf("%lld %lld", &n, &m) == 2)
    {
        if(n == 0 && m == 0)
        {
            printf("0 0\n");
            break;
        }
        v.clear();
        printf("%lld %lld\n", n, m);
        for(i = 0; i < n; ++i)
        {
            scanf("%lld", &a);
            info.u = a;
            info.v = a % m;
            v.push_back(info);
        }
        sort(v.begin(), v.end(), comp);
        for(i = 0; i < n; ++i)
            printf("%lld\n", v[i].u);
    }
    return 0;
}
