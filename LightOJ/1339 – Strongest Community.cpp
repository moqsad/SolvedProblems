#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int arr[100010], bistar[100010], num[100010], tree[400010], begin_, finish;

void build_tree(int node, int start, int end_)
{
    if(start == end_)
    {
        tree[node] = arr[start];
        return ;
    }
    int mid = (start + end_) / 2, left = 2 * node, right = 2 * node + 1;
    build_tree(left, start, mid);
    build_tree(right, mid + 1, end_);
    tree[node] = max(tree[left], tree[right]);
}

int query(int node, int start, int end_)
{
//    printf("%d %d  %d**********\n", node, start, end_);
    if(start >= begin_ && end_ <= finish)
        return tree[node];
    else if(start > finish || end_ < begin_)
        return 0;

    int mid = (start + end_) / 2, left = 2 * node, right = 2 * node + 1;
    return max(query(left, start, mid), query(right, mid + 1, end_));
}

int main()
{
    int t, cnt, n, c, q, i, j, k, a, x, y;
    scanf("%d", &t);
    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d %d %d", &n, &c, &q);
        j = 0;
        k = 0;
        x = 0;
        for(i = 1; i <= n; ++i)
        {
            scanf("%d", &a);
            if(a != x)
            {
                bistar[j] = i;
                x = a;
                arr[j++] = k;
                k = 1;
            }
            else
                ++k;
            num[i] = j;
        }

        bistar[j] = i;
        arr[j] = k;

//        for(i = 1; i <= n; ++i)
//            printf("bistar : %d____num : %d_____arr : %d\n", bistar[i], num[i], arr[i]);

        build_tree(1, 1, j);

        printf("Case %d:\n", cnt);
        for(i = 0; i < q; ++i)
        {
            scanf("%d %d", &begin_, &finish);

            if(num[begin_]  == num[finish])
                printf("%d\n", finish - begin_ + 1);
            else if(num[finish] - num[begin_] == 1)
                printf("%d\n", max(bistar[num[begin_]] - begin_, finish - bistar[num[begin_]] + 1));
            else
            {
                x = max(bistar[num[begin_]] - begin_, finish - bistar[num[finish] - 1] + 1);
                begin_ = num[begin_] + 1;
                finish = num[finish] - 1;
                y = query(1, 1, c);
//                printf("%d %d____________\n", num[j] + 1, num[k] - 1);
                printf("%d\n", max(x, y));
            }
        }
    }
    return 0;
}

/*
10
15 5 10
1 1 1 2 2 2 2 4 4 3 5 5 5 5 5
2 13
*/
