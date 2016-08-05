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

#define mod 1000000007

map <long long, long long> mm;

long long tree[100010 * 4], start_, end_, update_, arr[100010], for_map[100010];

void update(long long node, long long i, long long j)
{
    //printf("%lld %lld %lld__________________________________________________\n", node, i, j);

    if(i >= end_ && j <= end_)
    {
        tree[node] = (tree[node] + update_) % mod;
        return ;
    }

    //printf("%lld %lld %lld+++++++++++++++++++++++++++++++++++++++++++++++++\n", node, i, j);
    if(i > end_ || j < end_)
        return ;

    //printf("%lld %lld %lld hehehehehehehehhehehehhehehhehehehhehehhehehheh\n", node, i, j);

    long long left = node * 2, right = node * 2 + 1, mid = (i + j) / 2;

    update(left, i, mid);
    update(right, mid + 1, j);
    tree[node] = (tree[left] + tree[right]) % mod;
}

long long query(long long node, long long i, long long j)
{
    if(i >= start_ && j <= end_)
        return tree[node];

    if(i > end_ || j < start_)
        return 0;

    long long left = node * 2, right = node * 2 + 1, mid = (i + j) / 2;

    return (query(left, i, mid) + query(right, mid + 1, j)) % mod;
}

int main()
{
    long long t, n, cnt, i, j, sum;

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        memset(tree, 0, sizeof(tree));
        mm.clear();

        scanf("%lld", &n);

        for(i = 0; i < n; ++i)
        {
            scanf("%lld", &arr[i]);
            for_map[i] = arr[i];
        }

        sort(for_map, for_map + n);

        j = 0;
        sum = 0;

        for(i = 0; i < n; ++i)
        {
            if(mm.find(for_map[i]) == mm.end())
                mm[for_map[i]] = ++j;
        }

        //printf("%lld______\n", j);

        for(i = 0; i < n; ++i)
        {
            start_ = 1;
            end_ = mm[arr[i]] - 1;
            update_ = query(1, 1, j) + 1;
            sum = (sum + update_) % mod;
            //printf("%lld++++++++++++%lld\n", sum, mm[arr[i]]);
            end_ = mm[arr[i]];
            update(1, 1, j);
        }

        printf("Case %lld: %lld\n", cnt, sum);
    }

    return 0;
}
