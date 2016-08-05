#include <bits/stdc++.h>
using namespace std;

struct data
{
    long long index, v;
}cost[20005], info;

vector <data> vv;

bool comp(data p, data q)
{
    if(p.v != q.v)
    return p.v > q.v;
    else
        return p.index > q.index;
}

int main()
{
    long long t, cnt, s, c, b, e, i, j, max_, dist;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &s);
        cost[1].v = 0;
        cost[1].index = 1;
        for(i = 2; i <= s; ++i)
        {
            scanf("%lld", &c);
            cost[i].index = i;
            cost[i].v = cost[i - 1].v + c;
        }

        for(i = s; i > 0; --i)
            vv.push_back(cost[i]);

        sort(vv.begin(), vv.end(), comp);
        max_ = j = 0;

        for(i = 1; i <= s; ++i)
        {
            while(vv[j].index < i)
                ++j;
            dist = vv[j].v - cost[i].v;
            if(dist > max_)
            {
                max_ = dist;
                b = i;
                e = vv[j].index;
            }
            else if(dist == max_ && (vv[j].index - i) > (e - b))
            {
                b = i;
                e = vv[j].index;
            }
        }

        if(max_ > 0)
            printf("The nicest part of route %lld is between stops %lld and %lld\n", cnt, b, e);
        else
            printf("Route %lld has no nice parts\n", cnt);
        vv.clear();
    }    return 0;
}

/*
3
3
  -1
   6
10
   4
  -5
   4
  -3
   4
   4
  -4
   4
  -5
4
  -2
  -3
  -4
*/
