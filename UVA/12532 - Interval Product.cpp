#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int a, b, n, q, arr[100005], tree[500005];

char ans[100005];

void build_tree(int node, int s, int e)
{
    if(s == e)
    {
        if(arr[s] < 0)
            tree[node] = -1;
        else if(arr[s] > 0)
            tree[node] = 1;
        else
            tree[node] = 0;

        return ;
    }

    int left = 2 * node, right = 2 * node + 1, mid = (s + e) / 2;

    build_tree(left, s, mid);
    build_tree(right, mid + 1, e);

    tree[node] = tree[left] * tree[right];
}

void update(int node, int s, int e)
{
    if(s == e)
    {
        if(b < 0)
            tree[node] = -1;
        else if(b > 0)
            tree[node] = 1;
        else
            tree[node] = 0;

        return ;
    }

    int mid = (s + e) / 2, left = 2 * node, right = 2 * node + 1;

    if(a >= s && a <= mid)
        update(left, s, mid);
    else
        update(right, mid + 1, e);

    tree[node] = tree[left] * tree[right];
//    printf("%d : tree[node] : %d__________ %d %d-----------\n", node, tree[node], s, e);
}

int query(int node, int s, int e)
{
//    printf("%d %d %d-----------\n", node, s, e);
    if(s >= a && e <= b)
        return tree[node];

    int mid = (s + e) / 2, left = 2 * node, right = 2 * node + 1;

    if(mid < a)
        return query(right, mid + 1, e);

    else if(mid + 1 > b)
        return query(left, s, mid);

    else
        return query(left, s, mid) * query(right, mid + 1, e);
}

int main()
{
    char ch;
    int i, j, x;
    while(scanf("%d %d", &n, &q) == 2)
    {
        for(i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);

        build_tree(1, 1, n);

        j=0;

        for(i = 0; i < q; ++i)
        {
            scanf(" %c %d %d", &ch, &a, &b);

            if(ch == 'C')
                update(1, 1, n);

            else
            {
                x = query(1, 1, n);

                if(x == 0)
                    ans[j++] = '0';
                else if(x == -1)
                    ans[j++] = '-';
                else
                    ans[j++] = '+';
//                    printf("%c_________\n", ans[j-1]);
            }
        }

        for(i = 0; i < j; ++i)
            printf("%c", ans[i]);
        printf("\n");
    }
    return 0;
}
