#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct data
{
    string ch;
    int u;
};

char arr[110];

vector <data> v;

bool comp(data p, data q)
{
//    if(p.u == q.u)
//        return 1;
    return p.u < q.u; //keno mun soman hoileo agertake age rakhe?
}

int main()
{
    int m, n, i, l, t, j, k, x, cnt;
    data info;
    scanf("%d", &t);
    for(l = 1; l <= t; ++l)
    {
        scanf("%d %d", &m, &n);
        v.clear();
        for(cnt = 0; cnt < n; ++cnt)
        {
            scanf("%s", arr);
            x = strlen(arr);
            k = 0;
            for(i = 0; i < x; ++i)
                for(j = i + 1; j < x; ++j)
                {
                    if(arr[i] > arr[j])
                        ++k;
                }
            info.ch = arr;
            info.u = k;
            v.push_back(info);
        }
        stable_sort(v.begin(), v.end(), comp);
        for(i = 0; i < n; ++i)
            cout << v[i].ch << "\n";
        if(l < t)
            printf("\n");
    }
    return 0;
}
