#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int zero[500010], one[500010], two[500010], prop[500010], x, y, z;

void update(int node, int s, int e)
{
    if(s >= x && e <= y)
    {
        int temp = zero[node];
        zero[node] = two[node];
        two[node] = one[node];
        one[node] = temp;
        prop[node] = (prop[node] + 1) % 3;
        return ;
    }

    int mid = (s + e) / 2, left = 2 * node, right = 2 * node + 1;

    if(mid + 1 > y)
        update(left, s, mid);

    else if(mid < x)
        update(right, mid + 1, e);

    else
    {
        update(left, s, mid);
        update(right, mid + 1, e);
    }

    zero[node] = zero[left] + zero[right];
    one[node] = one[left] + one[right];
    two[node] = two[left] + two[right];

    if(prop[node] == 1)
    {
        int temp = zero[node];
        zero[node] = two[node];
        two[node] = one[node];
        one[node] = temp;
    }

    else if(prop[node] == 2)
    {
        int temp = zero[node];
        zero[node] = one[node];
        one[node] = two[node];
        two[node] = temp;
    }

    return ;
}

void build(int node, int s, int e)
{
    if(s == e)
    {
        zero[node] = 1;
        return ;
    }

    int mid = (s + e) / 2, left = 2 * node, right = 2 * node + 1;

    build(left, s, mid);
    build(right, mid + 1, e);

    zero[node] = zero[left] + zero[right];
}

int query(int node, int s, int e, int carry)
{
    if(s >= x && e <= y)
    {
        if(carry % 3 == 0)
            return zero[node];
        else if(carry % 3 == 1)
            return two[node];
        else
            return one[node];
    }

    int mid = (s + e) / 2, left = 2 * node, right = 2 * node + 1;

    if(mid + 1 > y)
        return query(left, s, mid, carry + prop[node]);

    if(mid < x)
        return query(right, mid + 1, e, carry + prop[node]);

    return query(left, s, mid, carry + prop[node]) + query(right, mid + 1, e, carry + prop[node]);
}

int main()
{
    int t, cnt, i, q, n, type;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {

        printf("Case %d:\n", cnt);
        scanf("%d %d", &n, &q);
        build(1, 1, n);
        memset(one, 0, sizeof(int) * 5 * n);
        memset(two, 0, sizeof(int) * 5 * n);
        memset(prop, 0, sizeof(int) * 5 * n);
        for(i = 1; i <= q; ++i)
        {
            scanf("%d %d %d", &type, &x, &y);
            x += 1;
            y += 1;
            if(type == 0)
                update(1, 1, n);
            else
                printf("%d\n", query(1, 1, n, 0));
        }
    }
    return 0;
}
