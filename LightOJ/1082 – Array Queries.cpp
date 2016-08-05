#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;

int arr[100010], tree[400010], s, e;

void build_tree(int node, int start, int end_)
{
    if(start == end_)
    {
        tree[node] = arr[start];
        return  ;
    }

    int left = node * 2, right = node * 2 + 1, mid = (start + end_) / 2;

    build_tree(left, start, mid);
    build_tree(right, mid + 1, end_);

    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int start, int end_)
{
    int  mid;
    if(start >= s && end_ <= e)
        return tree[node];
    else if(start > e || end_ < s)
        return 100000000;
    else
    {
        mid = (start + end_) / 2;
        return min(query(2 * node, start, mid), query(2 * node + 1, mid + 1, end_));
    }
}

int main()
{
    int i, n, q, t, cnt;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &q);
        for(i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);
        build_tree(1, 1, n);
        printf("Case %d:\n", cnt);
        for(i = 0; i < q; ++i)
        {
            scanf("%d %d", &s, &e);
            printf("%d\n", query(1, 1, n));
        }
    }
    return 0;
}

/*
7
4 -9 3 7 1 0 2
7
2 5
*/

