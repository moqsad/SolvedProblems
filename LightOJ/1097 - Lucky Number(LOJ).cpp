#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <iostream>
using namespace std;

#define sz 1429435

int tree[sz * 3], ans[sz], baki, n;

void build(int node, int i, int j)
{
    if(i == j)
    {
        tree[node] = i & 1;
        return ;
    }

    int left = 2 * node, right = 2 * node + 1, mid = (i + j) / 2;

    build(left, i, mid);
    build(right, mid + 1, j);
    tree[node] = tree[left] + tree[right];
}

void update(int node, int i, int j)
{
    if(i == j)
    {
        tree[node] = 0;
        return ;
    }

    int left = 2 * node, right = 2 * node + 1, mid = (i + j) / 2;

    if(baki <= tree[left])
        update(left, i, mid);
    else
    {
        baki -= tree[left];
        update(right, mid + 1, j);
    }

    tree[node] = tree[left] + tree[right];
}

int query(int node, int i, int j)
{
    if(i == j)
        return i;

    int left = 2 * node, right = 2 * node + 1, mid = (i + j) / 2;

    if(baki <= tree[left])
        return query(left, i, mid);
    else
    {
        baki -= tree[left];
        return query(right, mid + 1, j);
    }
}

void initial_work()
{
    int i, j, temp;

    build(1, 1, 1429431);

    ans[1] = 1;

    for(i = 2; i <= 100000; ++i)
    {
        baki = i;
        temp = ans[i] = query(1, 1, 1429431);

        j = (tree[1] / temp) * temp;

        for(; j > 0; j -= temp)
        {
            baki = j;
            update(1, 1, 1429431);
        }
    }
}

int main()
{
    int t, cnt;

    initial_work();

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);
        printf("Case %d: %d\n", cnt, ans[n]);
    }

    return 0;
}
