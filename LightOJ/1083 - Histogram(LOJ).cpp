#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int s, e, n, arr[30005], tree[150000];

void build_tree(int node, int start, int end_)
{
    if(start == end_)
    {
        tree[node] = start;
        return ;
    }

    int left = 2 * node, right = 2 * node + 1, mid = (start + end_) / 2;

    build_tree(left, start, mid);
    build_tree(right, mid + 1, end_);

    if(arr[tree[left]] < arr[tree[right]])
        tree[node] = tree[left];
    else
        tree[node] = tree[right];
}

int solve(int node, int start, int end_)
{
    if(start >= s && end_ <= e)
        return tree[node];

    int left = 2 * node, right = 2 * node + 1, mid = (start + end_) / 2, min1, min2;

    if(mid >= s)
    {
        min1 = solve(left, start, mid);
        if(mid + 1 <= e)
        {
            min2 = solve(right, mid + 1, end_);
            if(arr[min1] > arr[min2])
                min1 = min2;
        }
    }

    else
        min1 = solve(right, mid + 1, end_);

    return min1;
}

int func(int start, int end_)
{
    s = start, e = end_;

    int mid = solve(1, 1, n), left = 0, right = 0, max_;

    if(mid - 1 >= start)
    left = func(start, mid - 1);

    if(mid + 1 <= end_)
    right = func(mid + 1, end_);

    max_ = (end_ - start + 1) * arr[mid];

    return max(max_, max(left, right));
}

int main()
{
    int t, cnt, i;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        for(i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);


        build_tree(1, 1, n);
        s = 1, e = 4;
        printf("Case %d: %d\n", cnt, func(1, n));
    }
    return 0;
}
