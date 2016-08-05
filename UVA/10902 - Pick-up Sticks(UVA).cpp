#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct point
{
    double x, y;
};

struct line
{
    point s, e;
};

line l[100010];
bool color[100010];

double direction(point po, point from, point to)
{
    return (to.x - po.x) * (from.y - po.y) - (to.y -  po.y) * (from.x - po.x);
}

bool on_segment(point st, point end_, point in)
{
    if(in.x >= min(st.x, end_.x) && in.x <= max(st.x, end_.x) && in.y >= min(st.y, end_.y) && in.y <= max(st.y, end_.y))
        return true;
    return false;
}

bool line_segment(point p1, point p2, point p3, point p4)
{
    double d1, d2, d3, d4;

    d1 = direction(p1, p2, p3);
    d2 = direction(p1, p2, p4);
    d3 = direction(p3, p4, p1);
    d4 = direction(p3, p4, p2);

    if(((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;
    else if(d1 == 0 && on_segment(p1, p2, p3))
        return true;
    else if(d2 == 0 && on_segment(p1, p2, p4))
        return true;
    else if(d3 == 0 && on_segment(p3, p4, p1))
        return true;
    else if(d4 == 0 && on_segment(p3, p4, p2))
        return true;
    else
        return false;
}

int main()
{
    long long n, i, j;
    while(scanf("%lld", &n) == 1 && n)
    {
        memset(color, 0, sizeof(long long) * n);
        for(i = 1; i <= n; ++i)
            scanf("%lf %lf %lf %lf", &l[i].s.x, &l[i].s.y, &l[i].e.x, &l[i].e.y);

        for(i = 1; i < n; ++i)
        {
            for(j = i + 1; j <= n; j++)
                if(line_segment(l[i].s, l[i].e, l[j].s, l[j].e))
                {
                    color[i] = 1;
                    break;
                }
        }

        printf("Top sticks:");

        for(i = 1; i < n; ++i)
        {
            if(color[i] == 0)
                printf(" %lld,", i);
        }

        printf(" %lld.\n", n);
    }
    return 0;
}
