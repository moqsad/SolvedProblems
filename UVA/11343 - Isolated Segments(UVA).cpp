#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

struct point
{
    int x, y;
};

struct line
{
    point s, e;
};

line l[100010];

int direction(point po, point from, point to)
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
    int d1, d2, d3, d4;

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
    int n, i, j, f, ans, t, cnt;
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
            scanf("%d %d %d %d", &l[i].s.x, &l[i].s.y, &l[i].e.x, &l[i].e.y);

        for(i = 1; i <= n; ++i)
        {
            for(j = 1; j <= n; j++)
                if(i != j && line_segment(l[i].s, l[i].e, l[j].s, l[j].e))
                    break;
            if(j > n)
                ++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}

