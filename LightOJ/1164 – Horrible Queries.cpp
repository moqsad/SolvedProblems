#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

long long sum[500010], prop[500010], x, y, v;

void update(long long node, long long s, long long e)
{
    if(s >= x && e <= y)
    {
        sum[node] += (e - s + 1) * v;
        prop[node] += v;
        return ;
    }

    long long mid = (s + e) / 2;

    if(mid + 1 > y)
        update(2 * node, s, mid);

    else if(mid < x)
        update(2 * node + 1, mid + 1, e);

    else
    {
        update(2 * node, s, mid);
        update(2 * node + 1, mid + 1, e);
    }

    sum[node] = sum[2 * node] + sum[2 * node + 1] + (e - s + 1) * prop[node];
    return ;
}

long long query(long long node, long long s, long long e, long long carry)
{
    if(s >= x && e <= y)
        return sum[node] + (e - s + 1) * carry;

    long long mid = (s + e) / 2;

    if(mid + 1 > y)
        return query(2 * node, s, mid, carry + prop[node]);

    else if(mid < x)
        return query(2 * node + 1, mid + 1, e, carry + prop[node]);

    return query(2 * node, s, mid, carry + prop[node]) + query(2 * node + 1, mid + 1, e, carry + prop[node]);
}

int main()
{
    long long t, n, q, cnt, i, type;
    scanf("%lld", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        memset(sum, 0, sizeof(sum));
        memset(prop, 0, sizeof(prop));

        scanf("%lld %lld", &n, &q);
        printf("Case %lld:\n", cnt);
        for(i = 0; i < q; ++i)
        {
            scanf("%lld", &type);
            if(type == 0)
            {
                scanf("%lld %lld %lld", &x, &y, &v);
                ++x;
                ++y;
                update(1, 1, n);
            }

            else
            {
                scanf("%lld %lld", &x, &y);
                ++x;
                ++y;
                printf("%lld\n", query(1, 1, n, 0));
            }
        }
    }
    return 0;
}
/*
2
8 8
0 1 1 18
0 0 3 47
0 3 7 4
0 3 4 10
0 2 4 1
0 0 0 27
1 0 7
1 2 2
9 11
0 1 4 39
1 1 1
1 1 4
0 4 8 5
1 4 8
1 1 1
1 3 8
0 3 3 24
0 0 3 34
0 0 0 38
1 0 8
*/
