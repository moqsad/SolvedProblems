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

vector <long long> edge[1005];

#define mod 1000000007

long long combi[1005][1005], flag_[1005];

struct data
{
    long long value_, child_;
};

long long nCr(long long n, long long r)
{
    if(r == 0 || n == r)
        return 1;

    if(combi[n][r] != -1)
        return combi[n][r];

    return combi[n][r] = (nCr(n - 1, r - 1) + nCr(n - 1, r)) % mod;
}

data dfs(long long node)
{
    long long x = edge[node].size(), y, i, value2_;
    data info, info2, info3;

    info.value_ = 1;
    info.child_ = 1;

    for(i = 0; i < x; ++i)
    {
        y = edge[node][i];

        if(i == 0)
            info2 = dfs(y);
        else
        {
            info3 = dfs(y);
            value2_ = nCr(info2.child_ + info3.child_, info2.child_);
            info2.value_ = (value2_ * (info2.value_ * info3.value_) % mod) % mod;
            info2.child_ += info3.child_;
        }
    }

    if(x > 0)
    {
        info.value_ = info2.value_;
        info.child_ += info2.child_;
    }

    return info;
}

int main()
{
    long long n, t, cnt, i, a, b;
    data info;

    memset(combi, -1, sizeof(combi));

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);

        memset(flag_, 0, sizeof(flag_));

        for(i = 1; i < n; ++i)
        {
            scanf("%lld %lld", &a, &b);
            flag_[b] = 1;
            edge[a].push_back(b);
        }

        for(i = 1; i <= n; ++i)
            if(!flag_[i])
            {
                info = dfs(i);
                printf("Case %lld: %lld\n", cnt, info.value_);
                break;
            }

        for(i = 1; i <= n; ++i)
            edge[i].clear();
    }

    return 0;
}

/*
10
21
1 2
2 3
3 4
3 5
3 6
4 7
4 8
5 9
5 10
5 11
5 12
6 13
6 14
6 15
6 16
6 17
6 18
18 19
19 20
20 21

14
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
1 11
1 12
1 13
1 14
*/
