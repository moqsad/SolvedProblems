#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int x, y, v, i, sum[500010], latest[500010], man[500010];

void update(int node, int s, int e, int pre, int value)
{
    if(s >= x && e <= y)
    {
        sum[node] = (e - s + 1) * v;
        latest[node] = i;
        man[node] = v;
        return ;
    }

    int p, mid = (s + e) / 2, left = 2 * node, right = 2 * node + 1;

    if(latest[node] > pre)
    {
        p = latest[node];
        value = man[node];
    }
    else
        p = pre;

    latest[node] = p;

    if(mid + 1 > y)
    {
        update(left, s, mid, p, value);
        if(latest[right] < p)
            sum[right] = (e - mid) * value;
    }

    else if(mid < x)
    {
        update(right, mid + 1, e, p, value);
        if(latest[left] < p)
            sum[left] = (mid - s + 1) * value;
    }

    else
    {
        update(left, s, mid, p, value);
        update(right, mid + 1, e, p, value);
    }

    sum[node] = sum[left] + sum[right];
}

int query(int node, int s, int e, int pre, int value)
{
    int p, mid = (s + e) / 2, left = 2 * node, right = 2 * node + 1;

    if(s >= x && e <= y)
    {
        if(latest[node] < pre)
            return (e - s + 1) * value;
        else
            return sum[node];
    }

    if(latest[node] > pre)
    {
        p = latest[node];
        value = man[node];
    }
    else
        p = pre;

    if(mid + 1 > y)
        return query(left, s, mid, p, value);

    if(mid < x)
        return query(right, mid + 1, e, p, value);

    return query(left, s, mid, p, value) + query(right, mid + 1, e, p, value);
}

int gcd(int a, int b)
{
    int x = a, y = b, r;
    while(y > 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main()
{
    int t, cnt, n, q, g, type, ans;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        printf("Case %d:\n", cnt);
        memset(sum, 0, sizeof(sum));
        memset(latest, 0, sizeof(latest));
        scanf("%d %d", &n, &q);
        for(i = 1; i <= q; ++i)
        {
            scanf("%d %d %d", &type, &x, &y);
            x += 1;
            y += 1;
            if(type == 1)
            {
                scanf("%d", &v);
                update(1, 1, n, 0, 0);
            }

            else
            {
                ans = query(1, 1, n, 0, 0);
                g = gcd(ans, y - x + 1);
                if(g == y - x + 1)
                    printf("%d\n", ans / g);
                else
                    printf("%d/%d\n", ans / g, (y - x + 1) / g);
            }
        }
    }
    return 0;
}
