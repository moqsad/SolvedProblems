#include <cstdio>
#include  <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
using namespace std;

int arr[100010], max_tree[400010], min_tree[400010], begin_, finish;

void build_tree(int node, int start, int end_)
{
    if(start == end_)
    {
        min_tree[node] = max_tree[node] = arr[start];
        return ;
    }

    int mid = (start + end_) / 2, left = 2 * node, right = 2 * node + 1;

    build_tree(left, start, mid);
    build_tree(right, mid + 1, end_);
    max_tree[node] = max(max_tree[left], max_tree[right]);
    min_tree[node] = min(min_tree[left], min_tree[right]);
}

struct data
{
    int max_, min_;
};

data query(int node, int start, int end_)
{
    data info, x, y;
    if(start >= begin_ && end_ <= finish)
    {
        info.max_ = max_tree[node];
        info.min_ = min_tree[node];
        return info;
    }

    else if(start > finish || end_ < begin_)
    {
            info.max_ = 0;
            info.min_ = 1000000000;
            return info;
    }

    int mid = (start + end_) / 2, left = 2 * node , right = 2 * node + 1;
    x = query(left, start, mid);
    y = query(right, mid + 1, end_);
    info.max_ = max(x.max_, y.max_);
    info.min_ = min(x.min_, y.min_);
    return info;
}

int main()
{
    int cnt, n, i, x, d, ans, t;
    data info;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d", &n, &d);
        for(i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);
        build_tree(1, 1, n);

        ans = 0;
        x =  n - d + 1;
        for(i = 1; i <= x; ++i)
        {
            begin_ = i;
            finish = i + d - 1;
            info = query(1, 1, n);
            if(info.max_ - info.min_ > ans)
                ans = info.max_ - info.min_;
        }
        printf("Case %d: %d\n", cnt,  ans);
    }
    return 0;
}
