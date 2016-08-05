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

int main()
{
    long long t, cnt, n, i, ans, temp, two_;

    scanf("%lld", &t);

    for(cnt = 1; cnt <= t; ++cnt)
    {
        scanf("%lld", &n);

        two_ = 1;
        ans = 0;

        while(two_ <= n)
        {
            temp = sqrt(n / two_);
            ans += temp / 2 + (temp & 1);
            two_ *= 2;
        }

        printf("Case %lld: %lld\n", cnt, n - ans);
    }

    return 0;
}

