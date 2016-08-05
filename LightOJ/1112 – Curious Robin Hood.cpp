#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int arr[100010], tree[400010], s, e, point, add, ans;

void build_tree(int node, int start, int end_)
{
    if(start == end_)
    {
        tree[node] = arr[start];
//        printf("Range : %d  %d --> %d, sum : %d\n", start, end_, node, tree[node]);
        return  ;
    }

    int left = node * 2, right = node * 2 + 1, mid = (start + end_) / 2;

    build_tree(left, start, mid);
    build_tree(right, mid + 1, end_);

    tree[node] = tree[left] + tree[right];
//    printf("Range : %d  %d --> %d, sum : %d\n", start, end_, node, tree[node]);
}

int query(int node, int start, int end_)
{
    int  mid;
    if(start >= s && end_ <= e)
        return tree[node];
    else if(start > e || end_ < s)
        return 0;
    else
    {
        mid = (start + end_) / 2;
        return query(2 * node, start, mid) + query(2 * node + 1, mid + 1, end_);
    }
}

void update(int node, int start, int end_)
{

//    printf("%d %d %d____________\n", node, start, end_);
    if(point == start && point == end_)
    {
        ans = tree[node];
        if(add == 0)
            tree[node] = 0;
        else
            tree[node] += add;
        return;
    }

    int mid = (start + end_) / 2, left = 2 * node, right = 2 * node + 1;
    if(start <= point && point <= mid)
        update(left, start, mid);
    else
        update(right, mid + 1, end_);
    tree[node] = tree[left] +  tree[right];
}

int main()
{
    int i, n, q, t, cnt, a;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &q);
        for(i = 0; i < n; ++i)
            scanf("%d", &arr[i]);
        build_tree(1, 0, n - 1);

        printf("Case %d:\n", cnt);

        for(i = 0; i < q; ++i)
        {
            scanf("%d", &a);
            if(a == 1)
            {
                scanf("%d", &point);
                add = 0;
                update(1, 0, n - 1);
                printf("%d\n", ans);
            }

            else if(a == 2)
            {
                scanf("%d %d", &point, &add);
                update(1, 0, n - 1);
            }

            else
            {
                scanf("%d %d", &s, &e);
                printf("%d\n", query(1, 0, n - 1));
            }
        }
    }
    return 0;
}

