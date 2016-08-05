#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct data
{
    int day;
    int month;
    int year;
    char name[20];
};

vector <data> v;

bool comp(data p, data q)
{
    if(p.year != q.year)
        return p.year < q.year;
    else
    {
        if(p.month != q.month)
            return p.month < q.month;
        else
            return p.day < q.day;
    }
}

int main()
{
    int i, n;
    data info;
    while(scanf("%d", &n) == 1)
    {
        for(i = 0; i < n; ++i)
        {
            scanf("%s %d %d %d", info.name, &info.day, &info.month, &info.year);
            v.push_back(info);
        }
        sort(v.begin(), v.end(), comp);
        --n;
        printf("%s\n%s\n", v[n].name, v[0].name);
        v.clear();
    }
    return 0;
}

