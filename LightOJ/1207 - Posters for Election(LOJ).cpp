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

#define sz 200000

map <int, int> mm;

int tree[sz * 3], s, e, color, ans;

void update(int node, int i, int j)
{
    if(i > e || j < s)
        return ;

    if(i >= s && j <= e)
    {
        tree[node] = color;
        return ;
    }

    int left = 2 * node, right = 2 * node + 1, mid = (i + j) / 2;

    update(left, i, mid);
    update(right, mid + 1, j);
}

void query(int node, int i, int j, int pre)
{
    int max_ = max(pre, tree[node]);

    if(i == j)
    {
        if(max_ > 0 && mm.find(max_) == mm.end())
        {
            ++ans;
            mm[max_] = 1;
        }
        return ;
    }

    int left = 2 * node, right = left + 1, mid = (i + j) / 2;

    if(e >= i && e <= mid)
        query(left, i, mid, max_);
    else
        query(right, mid + 1, j, max_);

    return ;
}

int main()
{
    int t, cnt, temp, n, i;

    scanf("%d", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%d", &n);

        memset(tree, 0, sizeof(tree));

        temp = 2 * n;
        color = ans = 0;
        mm.clear();

        for(i = 0; i < n; ++i)
        {
            scanf("%d %d", &s, &e);
            ++color;
            update(1, 1, temp);
        }

        for(i = 1; i <= temp; ++i)
        {
            e = i;
            query(1, 1, temp, 0);
        }

        printf("Case %d: %d\n", cnt, ans);
    }

    return 0;
}

