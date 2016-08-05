#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int arr[100005], a, b;

struct data
{
    int left_data, left_ace, right_data, right_ace, value;
};

data tree[500005];

void build_tree(int node, int s, int e)
{
    data info;
    if(s == e)
    {
        info.value = 1;
        info.left_data = arr[s];
        info.left_ace = 1;
        info.right_data = arr[e];
        info.right_ace = 1;
        tree[node] = info;
        return ;
    }

    int mid = (s + e) / 2, left = 2 * node, right = 2 * node + 1, max_, x;
    build_tree(left, s, mid);
    build_tree(right, mid + 1, e);

    max_ = max(tree[left].value, tree[right].value);

    info.left_data = tree[left].left_data;
    info.right_data = tree[right].right_data;
    info.left_ace = tree[left].left_ace;
    info.right_ace = tree[right].right_ace;

    if(tree[left].right_data == tree[right].left_data)
    {
        x = tree[left].right_ace + tree[right].left_ace;
        if(tree[left].left_data == tree[left].right_data)
            info.left_ace = x;
        if(tree[right].right_data == tree[right].left_data)
            info.right_ace = x;
        max_ = max(x, max_);
    }

    info.value = max_;
    tree[node] = info;
    return ;
}

data find_ans(int node, int s, int e)
{
//    printf("%d %d___\n", s,  e);
    int mid = (s + e) / 2;

    if(s >= a && e <= b)
        return tree[node];

    if(mid >= a)
    {
        data info, info2, info3;
        int max_, left = 2 * node, right = 2 * node + 1, x;
        info = find_ans(left, s, mid);
//        printf("%d %d value : %d, ld : %d, la : %d, rd : %d, ra : %d.......1...\n", s, e, info.value, info.left_data, info.left_ace, info.right_data, info.right_ace);
        info3 = info;
        if(mid + 1 <= b)
        {
            info2 = find_ans(right, mid + 1, e);
//            printf("%d %d value : %d, ld : %d, la : %d, rd : %d, ra : %d......2...\n", s, e, info2.value, info2.left_data, info2.left_ace, info2.right_data, info2.right_ace);

            info3.right_data = info2.right_data;
            info3.right_ace = info2.right_ace;

            max_ = max(info.value, info2.value);

            if(info.right_data == info2.left_data)
            {
                x = info.right_ace + info2.left_ace;

                if(info.left_data == info.right_data)
                    info3.left_ace = x;

                if(info2.right_data == info2.left_data)
                    info3.right_ace = x;
                max_ = max(max_, x);
            }

            info3.value = max_;
        }
        return info3;
    }

    else
    {
        data info = find_ans(2 * node + 1,  mid + 1, e);
//        printf("%d %d value : %d, ld : %d, la : %d, rd : %d, ra : %d.....3...\n", s, e, info.value, info.left_data, info.left_ace, info.right_data, info.right_ace);
        return info;
    }
}

int main()
{
    int n, q, i;
    data info;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0)
            break;

        scanf("%d", &q);

        for(i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);

        build_tree(1, 1, n);

        for(i = 0; i < q; ++i)
        {
            scanf("%d %d", &a, &b);
            info = find_ans(1, 1, n);
            printf("%d\n", info.value);
        }
    }
    return 0;
}
